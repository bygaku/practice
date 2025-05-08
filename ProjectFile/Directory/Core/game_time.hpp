#pragma once
#include "memory"

class GameTime final
{
public:	
    GameTime() noexcept;
    ~GameTime() noexcept;

    /// @brief �t���[���J�E���g�� +1
    /// @remark ���t���[�������O�ɌĂяo��
    void incrementFrame() noexcept;

    /// @brief �Œ�t���[���̍X�V�񐔂��X�V���ĕԂ�
    int updateFixedFrameCount() noexcept;

    /// @brief ���݂�1�t���[���������� (seconds)
    [[nodiscard]] double getCurrentFrameTime() const noexcept;

    /// @brief fpsTarget_ �Ƃ��Ďw�肳��Ă��鎞�Ԃ܂ő҂�
    void sleepForNextFrame() const noexcept;

    /// @brief fps �������w��
    void setFpsTarget(int target) noexcept;

    /// @brief 2�O��1�O�̃t���[���Ԃ̎��ԍ� (seconds)
    static const float& getDeltaTime() noexcept { return dt_; }

private:
    /// @brief ���݂̃t���[���̎���
    [[nodiscard]] const LONGLONG& getTime() const noexcept { return time_; }

    /// @brief �Ō�� fps ���X�V�������� (nanoseconds)
    [[nodiscard]] const LONGLONG& getLastCheckedTime() const noexcept { return fpsCheckTime_; }

    /// @brief �N������̎��� (seconds)
    [[nodiscard]] const float& getTimeFromBoot() const noexcept { return timeSinceStartUp_; }

    /// @brief ���݂� frames per second
    [[nodiscard]] const int& getFps() const noexcept { return fps_; };

    /// @brief �Ō�� fps �X�V����̃t���[���J�E���g
    [[nodiscard]] const int& getFpsCounter() const noexcept { return fpsCounter_; };

    /// @brief ���݂� fps ����
    [[nodiscard]] const int& getFpsTarget() const noexcept { return fpsTarget_; };

    /// @brief ���݂� fps �����ɂ��t���[���Ԃ̕b�� (seconds)
    [[nodiscard]] const double& getSecondsPerFrame() const noexcept { return secondsPerFrame_; };

    /// @brief �Ō�̌Œ�Ԋu�X�V�̉�
    [[nodiscard]] const int& getLastFixedFrameCount() const noexcept { return lastFixedFrameCount_; };

    /// @brief �N�����Ă���̃t���[����
    [[nodiscard]] const unsigned int& getFrames() const noexcept { return frames_; };

private:
    static bool instantiated_;

    GameTime(const GameTime&) = delete;
    GameTime& operator=(const GameTime&) = delete;

private:
    LONGLONG time_;
    LONGLONG fpsCheckTime_;
    LONGLONG fixedUpdateCheckTime_;
    float    timeSinceStartUp_;

    int      fps_;
    int      fpsTarget_;
    int      fpsCounter_;
    double   secondsPerFrame_;
    int      lastFixedFrameCount_;

    static float dt_;
    unsigned int frames_;

};
