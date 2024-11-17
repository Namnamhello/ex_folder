#include <iostream>
#include <string.h>
#include <ctime>

using namespace std;

struct FileNode {
    string filename;
    long fileSize;
    time_t timeAdded;
    FileNode *next;
};

struct FileInfor{
    FileNode *head;
    FileInfor(){
        head =nullptr;
    }

  void addFile(string filename, long fileSize) {
    // Tạo một node mới
    FileNode* newNode = new FileNode;
    newNode->filename = filename;
    newNode->fileSize = fileSize;
    newNode->timeAdded = time(nullptr);
    newNode->next = nullptr; // Đảm bảo node mới có con trỏ next trỏ đến nullptr

    if (head == nullptr) {
        // Nếu danh sách đang rỗng, đặt head là node mới
        head = newNode;
    } else {
        // Duyệt đến cuối danh sách và thêm node mới
        FileNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    }
        // if(!head||node->fileSize<=head->fileSize){
        //     newNode->next = head;
        //     head = newNode;        
        // } else {
        //     FileNode* temp =head;
        //     while(temp->next && temp->next->fileSize<=newNode->fileSize){
        //         temp = temp->next;
        //     }
        //     newNode->next = temp->next;
        //     temp->next = newNode;
        // }
    void displayFiles() {
        if (head == nullptr) {
            cout << "Danh sách rỗng.\n";
            return;
        }

        FileNode* temp = head;
        cout << "Danh sách các file:\n";
        while (temp != nullptr) {
            cout << "Filename: " << temp->filename
                 << ", FileSize: " << temp->fileSize
                 << " KB, TimeAdded: " << ctime(&temp->timeAdded);
            temp = temp->next;
        }
        cout << endl;
    }
    void sortFile() {
        if (head == nullptr || head->next == nullptr) return; // Nếu danh sách rỗng hoặc chỉ có 1 phần tử

        FileNode* p;
        FileNode* q = nullptr;
        bool kt=true;

        while (kt) {
            kt = false;
            p = head;

            while (p->next != q) {
             if (p->fileSize > p->next->fileSize) {
                    // Hoán đổi dữ liệu giữa 2 node
                    swap(p->filename, p->next->filename);
                    swap(p->fileSize, p->next->fileSize);
                    swap(p->timeAdded, p->next->timeAdded);
                    kt = true; // Đánh dấu rằng có hoán đổi
                }
                p = p->next;
            }
            q = p; 
        }
    }
    
};

int main(){
    FileInfor fileList;

    // Thêm một số file vào danh sách
    fileList.addFile("File1.txt", 10934);
    fileList.addFile("File2.txt", 13847);
    fileList.addFile("File3.txt", 4995);
    fileList.addFile("File4.txt", 93289);
    fileList.addFile("File5.txt", 33844);

    cout << "Danh sách ban đầu:\n";
    fileList.displayFiles();

    // Sắp xếp danh sách theo kích thước file tăng dần
    fileList.sortFile();

    cout << "\nDanh sach sau khi sap xep:\n";
    fileList.displayFiles();

    return 0;
}