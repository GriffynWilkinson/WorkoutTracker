#include "WorkoutTracker.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	WorkoutTracker::WorkoutTracker form;
	Application::Run(%form);
}
