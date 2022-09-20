#include <iostream>
#include <string>
#include <vector>
#include <random>

template<typename T>
std::vector<T> slice(std::vector<T> const& v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;

    std::vector<T> vec(first, last);
    return vec;
}

std::vector < int > token(int len, int u, int l) {
    std::vector < int > arr;
    int s1 = u - l;
    if (s1 > len) {
        exit(0);
    }
    else {
        s1++;
        arr.push_back(l);
        for (int i = 1; i < s1; i++) {
            arr.push_back(++l);
        }
    }
    return arr;

}
std::vector < int > HashGenerator() {
    std::vector < int > a1, a2, a3;
    int r1, r2;
    a1 = token(90, 90, 65);
    a2 = token(122, 122, 97);
    std::random_device rd;
    std::mt19937 gnrt(rd());
    std::uniform_int_distribution < > d1(65, 90), d2(97, 122),d3(115,145);
    r1 = d1(gnrt);
    r2 = d2(gnrt);
    int r3 = d3(gnrt);
    a3 = token(r3, r2, r1);
    return slice(a3, 0, 7);

  
}

int main() {
    std::string senha;
    std::vector < int > token = HashGenerator();
    std::string str(token.begin(), token.end());
    for (int i = 0; i < 3; i++) {
        std::cout << "Para entrar digite sua senha:";
        std::cin >> senha;
        if (senha == str) {
            std::cout << "Logado!";
        }
        else {
            std::cout << "Senha errada" << std::endl;
        }
    }
    std::cout << "a senha era:";
    for (char i : str)
        std::cout << i;
    std::cout << std::endl;
    system("pause");
}
