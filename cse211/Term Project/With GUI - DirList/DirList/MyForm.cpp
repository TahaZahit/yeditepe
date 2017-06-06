#include "MyForm.h"
#include "ItemInfo.h"

namespace DirList {
	using namespace System;
	using namespace System::Windows::Forms;

	[STAThread]
	void main(array<String^>^ args) {
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		DirList::MyForm form;
		Application::Run(%form);
	}
}