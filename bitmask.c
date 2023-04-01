/*Cho một mảng số nguyên không âm và một số nguyên k, hãy viết chương trình để tìm tất cả các cặp số trong mảng mà tổng của chúng bằng k, 
sử dụng bitmask để tối ưu hóa thuật toán.*/

#include<stdio.h>
#include<stdint.h>

void findTwoNumberSumK(uint8_t arr[],int k, int length)
{
    for(int i = 0; i < (1<<length); i++)                 // ta co to hop cac ngo vao bang 2^length <==> 1<<length
    {
        uint8_t mask = 0;                                
        uint8_t soPhanTu = 0;   
        int TwoNumber[2];                               // luu 2 so can tim co sum =k
        
        for(int j = 0; j < length; j++)                 // Xet cac so trong to hop i
        {
            if((i & (1<<j)) > 0)                        // kiem tra so nao duoc chon trong to hop i
            {
                mask += arr[j];                         // Tinh tong cac so duoc chon
                TwoNumber[soPhanTu] = arr[j];           // luu vao mang
                soPhanTu += 1;                          // dem so phan tu 
            }
        }
        
        if(mask == k && soPhanTu == 2)
            printf("(%d, %d) ",TwoNumber[0] ,TwoNumber[1]); // kiem tra tong co = k và so phan tu = 2 khong
    }
}

int main()
{
    uint8_t arr[] = {1, 2, 3, 4, 5 ,6};
    int k = 6;
    int length = sizeof(arr) / sizeof(uint8_t);         // tinh so phan tu trong mang
    findTwoNumberSumK(arr, k, length);

    return 0;
}