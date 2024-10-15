#include <iostream>

int main()
{
    int Q, len;
    std::cin >> Q;

    for (int q = 0; q < Q; q++)
    {
        std::string str;

        std::cin >> len;
        std::cin >> str;

        int count = 0;

        for (int c = 1; c < len; c++)
        {
            if (str[c - 1] == str[c])
            {
                count++;
            }
        }

        std::cout << count << "\n";
    }

    return 0;
}