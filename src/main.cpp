#include <iostream>

bool check_str(std::string str) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != 'X' && str[i] != 'O' && str[i] != '.')
            return false;
    }
    return true;
}

int count_char(std::string str, char symbol) {
    int total = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == symbol)
            total++;
    }
    return total;
}

bool check_win_str(std::string str1, std::string str2, std::string str3, char symbol) {
    return (count_char(str1, symbol) == 3
        || count_char(str2, symbol) == 3
        || count_char(str3, symbol) == 3) ? true : false;
}

bool check_win_column(std::string str1, std::string str2, std::string str3, char symbol) {
    for (int i = 0; i < str1.length(); ++i) {
        if (str1[i] == symbol && str2[i] == symbol && str3[i] == symbol)
            return true;
    }
    return false;
}

bool check_win_diagonal(std::string str1, std::string str2, std::string str3, char symbol) {
    for (int i = 0, h = 0, j = 2; i < 2; ++i, h += 2, j -= 2) {
        if (str1[h] == symbol && str2[1] == symbol && str3[j] == symbol)
            return true;
    }
    return false;
}

bool search_win(std::string str1, std::string str2, std::string str3, char symbol) {
    return (!(check_win_str(str1, str2, str3, symbol))
        && !(check_win_column(str1, str2, str3, symbol))
        && !(check_win_diagonal(str1, str2, str3, symbol))) ? false : true;
}

std::string result(std::string str1, std::string str2, std::string str3) {
    std::string result;

    if (!(check_str(str1)) || !(check_str(str2)) || !(check_str(str3))) {
        result = "Incorrect";
        return result;
    }

    int sum_X = count_char(str1, 'X') + count_char(str2, 'X') + count_char(str3, 'X');
    int sum_O = count_char(str1, 'O') + count_char(str2, 'O') + count_char(str3, 'O');
    int sum_Points = count_char(str1, '.') + count_char(str2, '.') + count_char(str3, '.');

    if (search_win(str1, str2, str3, 'X') && sum_X - 1 == sum_O) {
        result = "Petya won";
        return result;
    }
    else if (search_win(str1, str2, str3, 'O') && sum_O == sum_X) {
        result = "Vanya won";
        return result;
    }
    else if (sum_X == 5 && sum_O == 4 && sum_Points == 0
        || sum_Points > sum_X && sum_X >= sum_O) {
        result = "Nobody";
        return result;
    }
    else {
        result = "Incorrect";
        return result;
    }

}

int main() {
    std::string str1, str2, str3;
    std::cin >> str1 >> str2 >> str3;

    std::cout << result(str1, str2, str3);
}