#include <iostream>

int main() {
    int n;
    std::cin >> n;
    while (n--) {
        int t1, t2, air1[26][26]={0}, air2[26][26]={0};
        std::cin >> t1;
        for (int i=0; i<t1; i++) {
            char city1, city2;
            std::cin >> city1 >> city2;
            air1[city1-'A'][city2-'A']=1;
            air1[city2-'A'][city1-'A']=1;
        }
        // A-B, B-D => A-D
        for (int i=0; i<26; i++) {
            for (int j=0; j<26; j++) {
                for (int k=0; k<26; k++) {
                    if (air1[j][i] && air1[i][k]) {
                        air1[j][k]=1;
                    }
                }
            }
        }
        std::cin>>t2;
        for (int i=0; i<t2; i++) {
            char city1, city2;
            std::cin >> city1 >> city2;
            air2[city1-'A'][city2-'A']=1;
            air2[city2-'A'][city1-'A']=1;
        }
        for (int i=0; i<26; i++) {
            for (int j=0; j<26; j++) {
                for (int k=0; k<26; k++) {
                    if (air2[j][i] && air2[i][k])
                        air2[j][k]=1;
                }
            }
        }
        int flag=1;
        for (int i=0; i<26; i++)
            for (int j=0; j<26; j++)
                if (air1[i][j] != air2[i][j])
                    flag=0;
        if (flag)
            std::cout << "YES" << std::endl << std::endl;
        else
            std::cout << "NO" << std::endl << std::endl;
    }
}
