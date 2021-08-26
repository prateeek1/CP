#include<bits/stdc++.h>
using namespace std;



struct trie
{
	trie* nxt[26];
	bool ended;
	trie()
	{
		for (int i = 0; i < 26; i++)
			nxt[i] = NULL;

		ended = false;
	}
};

trie* root;

void insert(string s)
{
	trie*cur = root;

	for (int i = 0; i < s.size(); i++)
	{
		if (cur->nxt[s[i] - 'a'] == NULL)
		{
			cur->nxt[s[i] - 'a'] = new trie();
			cur = cur->nxt[s[i] - 'a'];
		}

	}
	cur->ended = true;
}


bool in_trie(string s)
{
	trie* cur = root;

	for (int i = 0; i < s.size(); i++)
	{
		if (cur->nxt[s[i] - 'a'] == NULL)
		{
			return false;

		}
		cur = cur->nxt[s[i] - 'a'];

	}

	return true;

}

int main()
{
	root = new trie();

	string a = "abdwdjwdn";

	string b = "dwdj";

	for (int i = 0; i < a.size(); i++)
	{
		insert(a.substr(i));
	}


	if (in_trie(b))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;


}