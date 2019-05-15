/*-----------------------------
Copyright (c) 2019 M.I.T. License

Author(s):
- Jordan S.H. (blktux)

Note(s):
- Value of 1 means the call was
  terminated due to a flag had
  been called.
- Value of 0 means execution
  was successful.
- Value of (-1) means an unex-
  pected failure occured.
-----------------------------*/

#include <Windows.h>
#include <string>
#include <vector>
#include "../C/TypeDefinitions.h"

using string = std::string;

namespace Blacktux
{
    class Window {
    protected:
        std::vector<string> windowNames;
        bool OnDesktop(const string name);
    private:
        string m_name;
    public:
        Window(string name) : m_name("Undefined");
        ~Window();
        void UpdateName(const string newName);
        string GetName();
        DWORD GetProcessID();
        HANDLE GetWindowHandle();
        // This method will overwrite the given Window's address' value.
        template<typename T>
        volatile decltype(auto) WriteToProcess(DWORD address, T newValue);
    };
        
    bool Window::OnDesktop(const string name) {
        if (HWND hwnd = FindWindowA(NULL, name.c_str()) {
            return true;
        } else {
            return false;
        }
    }
    
    Window::Window(string name) : m_name("Undefined") {
        this->m_name = name;
    }
    
    Window::~Window() {
        delete (this);
    }
    
    void Window::UpdateName(const string newName) {
        this->m_name = newName;
    }
    
    string Window::GetName() {
        return this->m_name;
    }
    
    DWORD Window::GetProcessID() {
        if (OnDesktop(this->m_name)) {
            HWND hwnd = FindWindowA(NULL, this->m_name.c_str());
            DWORD procID;
            GetWindowThreadProcessId(hwnd, &procID);
            return &procID;
        } else if (!OnDesktop(this->m_name)) {
            return NULL;
        }
    }
    
    HANDLE Window::GetWindowHandle() {
        if (OnDisk(this->m_name)) {
            if (this->GetProcessID() != NULL) {
                HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, this->GetProcessID());
                if (handle) {
                    return handle;
                } else if (!handle) {
                    return NULL;
                }
            } else if (this->GetProcessID() == NULL) {
                return NULL;
            }
        } else if (!OnDisk(this->m_name)) {
            return NULL;
        }
    }
    
    template<typename T>
    volatile decltype(auto) Window::WriteToProcess(DWORD address, T newValue) {
        if (OnDesktop(this->m_name)) {
            if (this->GetProcessID) != NULL) {
                if (this->GetWindowHandle != NULL) {
                    if (WriteProcessMemory(this->GetWindowHandle(), (LPCVOID)address, newValue, sizeof(newValue), 0)) {
                        return newValue;
                    } else if (!WriteProcessMemory(this->GetWindowHandle(), (LPCVOID)address, newValue, sizeof(newValue), 0)) {
                        return 1;
                    }
                } else if (this->GetWindowHandle() == NULL {
                    return 1;
                }
            } else if (this->GetProcessID() == NULL) {
                return 1;
            }
        } else if (!OnDesktop(this->m_name)) {
            return 1;
        }
    }
} // namespace Blacktux
