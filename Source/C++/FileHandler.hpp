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

#include <fstream>
#include <string>
#include <vector>

using string = std::string;

namespace Blacktux 
{
    class File {
    protected:
        std::vector<string> filePaths;
        string lowChars = "abcdefghijklmnopqrstuvwxyz";
        string bigChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string numbers = "0123456789";
        bool OnDisk(const string path);
    private:
        string m_path;
    public:
        File(string path) : m_path("C:\\");
        ~File();
        void UpdatePath(const string newPath);
        string GetPath();
        short int Create();
        short int Append(string content);
        short int Overwrite(string content);
        short int Read();
    };
    
    bool File::OnDisk(const string path) {
        if (FILE *file = fopen(path.c_str(), "r")) {
            return true;
        } else {
            return false;
        }
    }
    
    File::File(string path) : m_path("C:\\") {
        this->m_path = path;
        filePaths.push_back(this->m_path);
    }
    
    File::~File() {
        delete (this);
    }
        
    void File::UpdatePath(const string newPath) {
        if (newPath.empty()) {
            this->m_path = "C:\\";
            return;
        } else {
            this->m_path = newPath;
            return;
        }
    }
    
    string File::GetPath() {
        return this->m_path;
    }
    
    short int File::Create() {
        if (OnDisk(this->m_path)) {
            std::ofstream file;
            file.open(this->m_path.c_str(), std::ios::write));
            if (file.is_open()) {
                file.close();
                return 0;
            }
        } else if (!OnDisk(this->m_path)) {
            return 1;
        }
    }
    
    short int File::Append(string content) {
        if (OnDisk(this->m_path)) {
            std::ofstream file;
            file.open(this->m_path.c_str(), std::ios::app));
            if (file.is_open()) {
                file << content;
                file.close();
                return 0;
            } else if (!file.is_open()) {
                return 1;
            }
        } else if (!OnDisk(this->m_path)) {
            return 1;
        }
    }
    
    short int File::Overwrite() {
        if (OnDisk(this->m_path)) {
            std::ofstream file;
            file.open(this->m_path.c_str(), std::ios::write));
            if (file.is_open()) {
                file << content;
                file.close();
                return 0;
            } else if (!file.is_open()) {
                return 1;
            }
        } else if (!OnDisk(this->m_path)) {
            return 1;
        }
    }
    
    short int File::Read() {
        if (OnDisk(this->m_path)) {
            std::ofstream file;
            file.open(this->m_path.c_str(), std::ios::read));
            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    std::cout << line;
                }
                file.close();
                return 0;
            } else if (!file.is_open()) {
                return 1;
            }
        } else if (!OnDisk(this->m_path)) {
            return 1;
        }
    }
} // namespace Blacktux
