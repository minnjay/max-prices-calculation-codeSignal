#include "stdc++.h"

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// answer 22

int maxGain(vector<int> prices, vector<int> algo, int k)
{
    int sum = 0;


    for(int i = 0; i<k ; ++i)
    {
        sum += prices[i];
    }

    for(int i = k; i<algo.size() ; ++i)
    {
        if(algo[i] == 1)
        {
            sum += prices[i];
        }
        else
        {
            sum -= prices[i];
        }
    }

    int max = sum;
    for(int i = 0; i< prices.size()-k-1; ++i)
    {
        if(algo[k+i] == 0)
        {
            sum += 2*prices[k+i];
        }

        if(algo[i] == 0)
        {
            sum -= 2*prices[i];
        }
        if(max < sum)
        {
            max = sum;
        }

    }

    return max;
}

int main()
{
    ifstream in("test_ebay.txt");

    string k_temp;
    getline(in, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string scores_count_temp;
    getline(in, scores_count_temp);

    int scores_count = stoi(ltrim(rtrim(scores_count_temp)));

    vector<int> pricess(scores_count);
    vector<int> algos(scores_count);

    for (int i = 0; i < scores_count; i++)
    {
        string scores_item_temp;
        getline(in, scores_item_temp);

        int scores_item = stoi(ltrim(rtrim(scores_item_temp)));

        pricess[i] = scores_item;
    }

    for (int i = 0; i < scores_count; i++)
    {
        string scores_item_temp;
        getline(in, scores_item_temp);

        int scores_item = stoi(ltrim(rtrim(scores_item_temp)));

        algos[i] = scores_item;
    }



    int result = maxGain(pricess, algos, k);

    cout << result << "\n";
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}