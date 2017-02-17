#pragma once
#include <cstdio>

namespace Ionic {
	namespace Utils {

		class FPSCounter
		{
		public:
			FPSCounter();
			void Start();
			void Update(double currentTime);
			inline bool NeedsUpdate() const { return _currTime - _lastTime >= 1.0; }
			float GetFPS();
			void Reset();
		private:
			int _frames;
			double _lastTime;
			double _currTime;

		};

	}
}