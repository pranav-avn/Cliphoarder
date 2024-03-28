#include <Windows.h>
#include <stdio.h>

int main(){
    
    //OpenClipboard returns zero if the function fails
    //OpenClipboard with NULL parameter passed accesses the clipboard associated with the current task
    
    if (!OpenClipboard(NULL)){
        return 1;
    }

    HANDLE data = GetClipboardData(CF_TEXT);
    if (data == NULL){
        CloseClipboard();
        return 1;
    }
    printf("Contents: %s\n", data);

    CloseClipboard();

    return 0;


}