#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

struct topic
{
	string name;
	int page;
	topic* next;
	topic* sub;
}*t_head, * tec_t, * tec_sub, * alph, * alph1;

struct hash_t
{
	struct topic* name;
	hash_t* next;
} *h_head, * tec, * tek;

int Seek_s()
{
	hash_t* h = new hash_t;
	topic* t = new topic;
	topic* temp = new topic;
	h = h_head;
	cout << "Enter topic: ";
	string s = "";
	cin >> s;
	cout << s  << endl;
	h = h_head;
	while (h != NULL)
	{
		if (h->name->name == s)
		{
			t = h->name->sub;
			while (t != NULL)
			{
				cout << "	" << t->name << endl;
				temp = t->sub;
				while (temp != NULL)
				{
					cout << "		" << temp->name << endl;
					temp = temp->next;
				}
				t = t->next;
			}
			return 0;
		}
		h = h->next;
	}

	h = h_head;
	while (h != NULL)
	{
		t = h->name->sub;
		while (t != NULL)
		{
			if (t->name == s)
			{
				temp = t->sub;
				while (temp != NULL)
				{
					cout << "	" << temp->name << endl;
					temp = temp->next;
				}
				//return 0;
			}
			t = t->next;
		}
		h = h->next;
	}
	return 0;
}

int Seek_t()
{
	hash_t* h = new hash_t;
	topic* t = new topic;
	topic* temp = new topic;
	h = h_head;
	cout << "Enter subtopic: ";
	string s = "";
	cin >> s;
	while (h != NULL)
	{
		t = h->name->sub;
		while (t != NULL)
		{
			temp = t->sub;
			while (temp != NULL)
			{
				if (temp->name == s)
				{
					cout << "Main: " << h->name->name << ",  Head: " << t->name << endl;
					//return 0;
				}
				temp = temp->next;
			}
			t = t->next;
		}

		h = h->next;
	}

	h = h_head;
	while (h != NULL)
	{
		t = h->name->sub;
		while (t != NULL)
		{
			if (t->name == s)
			{
				cout << "Head: " << h->name->name << endl;
				//return 0;
			}
			t = t->next;
		}
		h = h->next;
	}
	return 0;
}

int page_sss(const std::string& item)
{
	topic* t = new topic;
	t = alph1;
	while (t != NULL)
	{
		if (to_string(t->page) == item)
		{
			cout << "		" << t->name << "  p. " << item << endl;
			return 0;
		}
		t = t->next;
	}
}

int page_ss(const std::string& item)
{
	topic* t = new topic;
	topic* temp = new topic;
	std::set<std::string> sortedItems;
	t = alph;
	while (t != NULL)
	{
		if (to_string(t->page) == item)
		{
			cout << "	" << t->name << "  p. " << item << endl;
			temp = t->sub;
			alph1 = temp;
			while (temp != NULL)
			{
				sortedItems.insert(to_string(temp->page));
				temp = temp->next;
			}
			std::for_each(sortedItems.begin(), sortedItems.end(), &page_sss);
			return 0;
		}
		t = t->next;
	}
}

int page_s(const std::string& item)
{
	hash_t* h = new hash_t;
	topic* t = new topic;
	std::set<std::string> sortedItems;
	h = h_head;
	while (h != NULL)
	{
		if (to_string(h->name->page) == item)
		{
			cout << h->name->name << "  p. " << item << endl;
			t = h->name->sub;
			alph = t;
			while (t != NULL)
			{
				sortedItems.insert(to_string(t->page));
				t = t->next;
			}
			std::for_each(sortedItems.begin(), sortedItems.end(), &page_ss);
			return 0;
		}
		h = h->next;
	}
}

void Page()
{
	hash_t* h = new hash_t;
	std::set<std::string> sortedItems;
	h = h_head;
	cout << "Page order" << endl;
	int i = 0;
	while (h != NULL)
	{
		sortedItems.insert(to_string(h->name->page));
		h = h->next;
	}

	std::for_each(sortedItems.begin(), sortedItems.end(), &page_s);
}

int print_ss(const std::string& item)
{
	topic* t = new topic;
	t = alph1;
	while (t != NULL)
	{
		if (t->name == item)
		{
			cout << "		" << item << "  p. " << t->page << endl;
			return 0;
		}
		t = t->next;
	}
}

int print_s(const std::string& item)
{
	topic* t = new topic;
	topic* temp = new topic;
	std::set<std::string> sortedItems;
	t = alph;
	while (t != NULL)
	{
		if (t->name == item)
		{
			cout << "	" << item << "  p. " << t->page << endl;
			temp = t->sub;
			alph1 = temp;
			while (temp != NULL)
			{
				sortedItems.insert(temp->name);
				temp = temp->next;
			}
			std::for_each(sortedItems.begin(), sortedItems.end(), &print_ss);
			return 0;
		}
		t = t->next;
	}
}

int print(const std::string& item)
{
	hash_t* h = new hash_t;
	topic* t = new topic;
	std::set<std::string> sortedItems;
	h = h_head;
	while (h != NULL)
	{
		if (h->name->name == item)
		{
			cout << item << "  p. " << h->name->page << endl;
			t = h->name->sub;
			alph = t;
			while (t != NULL)
			{
				sortedItems.insert(t->name);
				t = t->next;
			}
			std::for_each(sortedItems.begin(), sortedItems.end(), &print_s);
			return 0;
		}
		h = h->next;
	}
}

void Alphabet()
{
	hash_t* h = new hash_t;
	std::set<std::string> sortedItems;
	h = h_head;
	cout << "Alphabet order" << endl;
	int i = 0;
	while (h != NULL)
	{
		sortedItems.insert(h->name->name);
		h = h->next;
	}

	std::for_each(sortedItems.begin(), sortedItems.end(), &print);
}

void Print()
{
	hash_t* h = new hash_t;
	topic* t = new topic;
	topic* temp = new topic;
	h = h_head;
	cout << "Here is all CONTENT" << endl;
	while (h != NULL && h->name != NULL)
	{
		cout << h->name->name << "  p. " << h->name->page << endl;
		t = h->name->sub;
		while (t != NULL)
		{
			cout << "	" << t->name << "  p. " << t->page << endl;
			temp = t->sub;
			while (temp != NULL)
			{
				cout << "		" << temp->name << "  p. " << temp->page << endl;
				temp = temp->next;
			}
			t = t->next;
		}
		h = h->next;
	}
}

int Del()
{
	cout << "Enter topic TITLE: ";
	string s;
	cin >> s;
	hash_t* h = new hash_t;
	topic* t = new topic;
	topic* temp = new topic;
	h = h_head;
	while (h != NULL)
	{
		if (h->name->name == s)
		{
			tek = h_head;
			if (tek == h)
			{
				h_head = h->next;
				h = 0;
				return 0;
			}

			if (h->next == NULL)
			{
				while (tek->next != h)
				{
					tek = tek->next;
				}
				tek->next = NULL;
				h = 0;
				return 0;
			}
			else
			{
				while (tek->next != h)
				{
					tek = tek->next;
				}
				tek->next = h->next;
				h = 0;
				return 0;
			}
		}
		h = h->next;
	}

	h = h_head;
	while (h != NULL)
	{
		t = h->name->sub;
		while (t != NULL)
		{
			if (t->name == s)
			{
				temp = h->name->sub;
				if (temp == t)
				{
					h->name->sub = temp->next;
					temp = 0;
					return 0;
				}

				if (t->next == NULL)
				{
					while (temp->next != t)
					{
						temp = temp->next;
					}
					temp->next = NULL;
					t = 0;
					return 0;
				}

				else
				{
					while (temp->next != t)
					{
						temp = temp->next;
					}
					temp->next = t->next;
					t = 0;
					return 0;
				}
			}
			t = t->next;
		}

		h = h->next;
	}

	h = h_head;
	while (h != NULL)
	{
		t = h->name->sub;
		while (t != NULL)
		{
			temp = t->sub;
			while (temp != NULL)
			{
				if (temp->name == s)
				{
					alph = t->sub;
					if (alph == temp)
					{
						t->sub = temp->next;
						temp = 0;
						return 0;
					}

					if (temp->next == NULL)
					{
						while (alph->next != temp)
						{
							alph = alph->next;
						}
						alph->next = NULL;
						temp = 0;
						return 0;
					}

					else
					{
						while (alph->next != temp)
						{
							alph = alph->next;
						}
						alph->next = temp->next;
						temp = 0;
						return 0;
					}
				}
				temp = temp->next;
			}
			t = t->next;
		}

		h = h->next;
	}
}

void Add_sub_sub()
{
	topic* t = new topic;
	topic* temp = new topic;
	cout << "Enter topic title: ";
	cin >> t->name;
	cout << "Enter page: ";
	cin >> t->page;
	t_head = tec_t->sub;
	if (t_head == NULL)
	{
		tec_t->sub = t;
	}
	else
	{
		tec_sub->next = t;
	}
	tec_sub = t;
	tec_sub->next = NULL;
	tec_sub->sub = NULL;
}

void Add_sub()
{
	topic* t = new topic;
	cout << "Enter topic title: ";
	cin >> t->name;
	cout << "Enter page: ";
	cin >> t->page;
	if (tec->name->sub == NULL)
	{
		tec->name->sub = t;
		t_head = tec->name->sub;
	}
	else
	{
		tec_t->next = t;
	}
	t->next = NULL;
	t->sub = NULL;
	tec_t = t;
}

void Add()
{
	hash_t* p = new hash_t;
	topic* t = new topic;
	cout << "Enter topic title: ";
	cin >> t->name;
	cout << "Enter page: ";
	cin >> t->page;
	t->next = NULL;
	t->sub = NULL;
	p->name = t;
	p->next = NULL;

	if (h_head == NULL)
	{
		h_head = p;
	}
	else
	{
		tec->next = p;
	}
	p->next = NULL;
	tec = p;
}

int main()
{
	cout << "Welcome on the Table of contents!" << endl;
	cout << endl << "1 - add topic, 2 - delete topic, 3 - sort by alphabet, 4 - sort by page, 5 - seek, 6 - print, 7 - exit" << endl;
	int x = 0;
	cin >> x;
	while (x != 7)
	{
		if (x == 1)
		{
			Add();
			cout << "1 - add subtopic, 2 - continue" << endl;
			int i = 0;
			cin >> i;
			while (i != 2)
			{
				Add_sub();
				cout << "1 - add sub-subtopic, 2 - continue" << endl;
				int j = 0;
				cin >> j;
				while (j != 2)
				{
					Add_sub_sub();
					cout << "1 - add sub-subtopic, 2 - continue" << endl;
					cin >> j;
				}
				cout << "1 - add subtopic, 2 - continue" << endl;
				cin >> i;
			}
		}

		if (x == 2)
		{
			Del();
		}

		if (x == 3)
		{
			Alphabet();
		}

		if (x == 4)
		{
			Page();
		}

		if (x == 5)
		{
			cout << "1 - Topic by subtopic, 2 - subtopics by topic" << endl;
			int k = 0;
			cin >> k;
			if (k == 1)
			{
				Seek_t();
			}

			if (k == 2)
			{
				Seek_s();
			}
		}

		if (x == 6)
		{
			Print();
		}

		cout << endl << "1 - add topic, 2 - delete topic, 3 - sort by alphabet, 4 - sort by page, 5 - seek, 6 - print, 7 - exit" << endl;
		cin >> x;
	}
}