#include "DxLib.h"
#include "Utility/assert_for_dxlib.hpp"
#include "Core/game_time.hpp"

bool  GameTime::instantiated_ = false;
float GameTime::dt_           =  0.0f;

GameTime::GameTime() noexcept
    : time_(0)
    , fpsCheckTime_(0)
    , fixedUpdateCheckTime_(0)
    , timeSinceStartUp_(0.0f)
    , fps_(0)
    , fpsCounter_(0)
    , lastFixedFrameCount_(0)
    , fpsTarget_(60)
    , secondsPerFrame_(1.0 / fpsTarget_)
    , frames_(0)
{
    ASSERT(instantiated_ == 0, "already instantiated.");
    instantiated_ = true;

    // �N���̃^�C�~���O�ŃV�X�e�����Ԃ���
    time_ = GetNowHiPerformanceCount();
    fpsCheckTime_ = GetNowHiPerformanceCount();
    fixedUpdateCheckTime_ = GetNowHiPerformanceCount();
}

GameTime::~GameTime() noexcept
{
    instantiated_ = false;
}

void GameTime::incrementFrame() noexcept
{
    ScreenFlip();
 
    // �f���^�^�C���Z�o
    const LONGLONG now = GetNowHiPerformanceCount();
    dt_   = (now - time_) / 1000000.0f;
    time_ =  now;

    // 1�b�o�߂���ԂɎ��s���ꂽ���C�����[�v�̉񐔂� GameTime �Ƃ���
    ++fpsCounter_;

    if (now - fpsCheckTime_ > 1000000.0f)
    {
        fps_ = fpsCounter_;
        fpsCounter_ = 0;
        fpsCheckTime_ = now;
    }

    // dt_ �𖈃t���[�������āA�b�Z�o
    timeSinceStartUp_ += dt_;
}

int GameTime::updateFixedFrameCount() noexcept
{
    int frame_counts = 0;
    while (fixedUpdateCheckTime_ < time_)
    {
        fixedUpdateCheckTime_ += 20000;
        frame_counts++;
    }

    lastFixedFrameCount_ = frame_counts;
    return frame_counts;
}

double GameTime::getCurrentFrameTime() const noexcept
{
    // 1�t���[���̎��Ԃ��Z�o
    const LONGLONG now = GetNowHiPerformanceCount();
    return (now - time_) / 1000000.0;
}

void GameTime::sleepForNextFrame() const noexcept
{
    auto frametime = getCurrentFrameTime();
    if (getSecondsPerFrame() > frametime) 
    {
        WaitTimer(static_cast<int>(getSecondsPerFrame() - frametime) * 1000);
    }
}

void GameTime::setFpsTarget(int target) noexcept
{
    if (target == -1)
    {
        fpsTarget_ = target;
        secondsPerFrame_ = 0;
        return;
    }

    fpsTarget_ = target;
    secondsPerFrame_ = 1.0 / fpsTarget_;
}
