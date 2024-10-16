template <class T>
void naiveInsertionSort(T* arr, int len) 
{
    for (int i = 1; i < len; i++)
    {
        int elIndex = i; 
        while (elIndex > 0 && arr[elIndex] < arr[elIndex - 1])
        {
            std::swap(arr[elIndex], arr[elIndex - 1]); 
            elIndex--;
        }
    }
}