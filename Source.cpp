#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string getLongestCommonSubsequence(const string& a, const string& b)
{
    vector<vector<int> > max_len;
    max_len.resize(a.size() + 1);
    for (int i = 0; i <= static_cast<int>(a.size()); i++)
        max_len[i].resize(b.size() + 1);
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; i--)
    {
        for (int j = static_cast<int>(b.size()) - 1; j >= 0; j--)
        {
            if (a[i] == b[j])
            {
                max_len[i][j] = 1 + max_len[i + 1][j + 1];
            }
            else
            {
                max_len[i][j] = max(max_len[i + 1][j], max_len[i][j + 1]);
            }
        }
    }
    string res;
    for (int i = 0, j = 0; max_len[i][j] != 0 && i < static_cast<int>(a.size()) && j < static_cast<int>(b.size()); )
    {
        if (a[i] == b[j])
        {
            res.push_back(a[i]);
            i++;
            j++;
        }
        else
        {
            if (max_len[i][j] == max_len[i + 1][j])
                i++;
            else
                j++;
        }
    }
    return res;
}



int main() 
{

    string str1, str2, str3, str4;


    ifstream f1("C:/infa/1_file.txt", ios::binary | ios::in); //считываю
    getline(f1, str1);



    ifstream f2("C:/infa/2_file.txt", ios::binary | ios::in); 
    getline(f2, str2);
  

    str3 = getLongestCommonSubsequence(str1, str2); //нахожу наибольшую подстроку

    str3 += "END";

    int a = 0;

    for (int i = 0; i < str1.length();i++)//создаю строку разницы
    {
        if ((str1[i] != str3[a])&&(str2[i] != str3[a]))
        {
            str4 += "-";
            str4 += str1[i];
            str4 += "+";
            str4 += str2[i];
        }
        else if((str1[i] == str3[a]) && (str2[i] == str3[a]))
        {
            ++a;
            str4 += "|";
        }
        else if ((str1[i] != str3[a]) && (str2[i] == str3[a]))
        {
            str4 += "-";
            str4 += str1[i];
        }
        else if ((str1[i] == str3[a]) && (str2[i] != str3[a]))
        {
            str4 += "+";
            str4 += str2[i];
        }
    }
  




    ofstream f3("C:/infa/3_file.txt", ios::binary | ios::out);
    f3 << str4;







    f1.close();    
    f2.close();
    f3.close();


}

