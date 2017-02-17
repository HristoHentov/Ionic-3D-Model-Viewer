#include "FPSCounter.h"
namespace Ionic {
	namespace Utils {
		FPSCounter::FPSCounter()
		{
			_lastTime = 0.0f;
			_currTime = 0.0f;
			_frames = 0;
		}

		void FPSCounter::Start()
		{
			_lastTime = 0.0f;
			_frames = 0;
		}

		void FPSCounter::Update(double currentTime)
		{
			_currTime = currentTime;
			_frames++;
		}

		float FPSCounter::GetFPS()
		{
			double fps = _frames / (_currTime - _lastTime);
			_frames = 0;
			_lastTime += 1.0f;

			return fps;
		}

		void FPSCounter::Reset()
		{
			_currTime = 0.0f;
			_lastTime = 0.0f;
			_frames = 0;
		}
	}
}