problem 1


#include <bits/stdc++.h>
using namespace std;


vector<int> generateHammingCode(vector<int> msgBits, int m, int r)
{
	
	vector<int> hammingCode(r + m);


	for (int i = 0; i < r; ++i) {

	
		hammingCode[pow(2, i) - 1] = -1;
	}

	int j = 0;


	for (int i = 0; i < (r + m); i++) {

		if (hammingCode[i] != -1) {
			hammingCode[i] = msgBits[j];
			j++;
		}
	}

	for (int i = 0; i < (r + m); i++) {

		if (hammingCode[i] != -1)
			continue;

		int x = log2(i + 1);//koto ghor sift korbe
		int one_count = 0;

	
		for (int j = i + 2; j <= (r + m); ++j) {
            cout<<j<<" "<<x<<" "<< (1 << x)<<endl;
			if (j & (1 << x)) {
				if (hammingCode[j - 1] == 1) {
					one_count++;
				}
			}
		}
        cout<<endl<<endl;


        cout<<one_count<<endl;
		if (one_count % 2 == 0) {
			hammingCode[i] = 0;
		}
		else {
			hammingCode[i] = 1;
		}
	}

	
	return hammingCode;
}

void findHammingCode(vector<int>& msgBit)
{


	int m = msgBit.size();
	int r = 1;

	while (pow(2, r) < (m + r + 1)) {
		r++;
	}

	vector<int> ans = generateHammingCode(msgBit, m, r);

	cout << "Message bits are: ";
	for (int i = 0; i < msgBit.size(); i++)
		cout << msgBit[i] << " ";

	cout << "\nHamming code is: ";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}

int main()
{
	
	vector<int> msgBit = {1,0,0,1,1,1,0,1};

	
	findHammingCode(msgBit);

	return 0;
}



problem 2
  
#include <bits/stdc++.h>
using namespace std;

// A Huffman tree node
struct MinHeapNode {
	char data;
	unsigned freq; 

	MinHeapNode *left, *right;

	MinHeapNode(char data, unsigned freq)
	{

		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};


struct compare {

	bool operator()(MinHeapNode* l, MinHeapNode* r)

	{
		return (l->freq > r->freq);
	}
};

void printCodes(struct MinHeapNode* root, string str)
{
   

	if (!root)
		return;

	if (root->data != '$')
		cout << root->data << ": " << str << "\n";

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
	struct MinHeapNode *left, *right, *top;


	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

	for (int i = 0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));


	while (minHeap.size() != 1) {

	
        //cout<<minHeap.top()->data<<endl;
		left = minHeap.top();
		minHeap.pop();
        //cout<<"left= "<<left->data<<" "<<left->freq<<endl;
		right = minHeap.top();
		minHeap.pop();

		top = new MinHeapNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;
        cout<<top->data<<endl;
		minHeap.push(top);
	}

	printCodes(minHeap.top(), "");
}

// Driver Code
int main()
{

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	HuffmanCodes(arr, freq, size);

	return 0;
}




#include<bits/stdc++.h>
using namespace std;

int main()
{
    string input_sequence;
    cout<<"enter the sequence"<<endl;
    // cin>>input_sequence;
    input_sequence="000101110010100101";
    int len = input_sequence.size();
    cout<<len<<endl;

    unordered_map<string,int>substring_track;
    vector<pair<int,string>>pre_ans;

    substring_track["0"] = 1;
    substring_track["1"] = 2;
    pre_ans.push_back({0,"0"});
    pre_ans.push_back({0,"1"});

    string pre_sub_string="";
    string next ="";
    int sub_string_index = 3;


    for(int i=0;i<len;){
         
         string sub_string = "";
         //cout<<i<<" "<<"okk"<<endl;
         sub_string += input_sequence[i];
         i++;
         while(substring_track[sub_string] && i<len)
         {
            pre_sub_string= sub_string;
            sub_string+=input_sequence[i];
           // cout<<sub_string<<endl;
            next = input_sequence[i];
            i++;
         }
         if(!substring_track[sub_string] and i<=len)
         {
            substring_track[sub_string] = sub_string_index;
           // cout<<sub_string<<" "<<"okk2"<<endl;
            int first = substring_track[pre_sub_string];
            string second = (next);
            pre_ans.push_back({first,second});
 
            //for control the index
            sub_string_index += 1;
         }
         
         cout<<endl;
        
    }

    for(auto it : pre_ans){
            cout<<bitset<3>(it.first)<<it.second<<"  ";
         }
}



problem 4
  
  #include<bits/stdc++.h>

using namespace std;

vector<int>generate_g(string G){
    vector<int>g;
    for(int i = 0; i < G.length(); i++)
    {
        if(G[i]=='1')
        {
            g.push_back(i);
        }
    }
    return g;
}

vector<int> multiply(vector<int> g, vector<int> m)
{
    vector<int>y;
    for(int i = 0; i < g.size(); i++)
    {
        for(int j = 0; j < m.size(); j++)
        {
            y.push_back(g[i]+m[j]);
        }
    }
    return y;
}

void printv(vector<int>v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

main(){
    string G2 = "011", G1 = "100";
    string message;
    cout<<"Enter the message bit sequence : ";
    cin>>message;

    vector<int>g1, g2, m;

    int i=0;
    g1 = generate_g(G1);
    g2 = generate_g(G2);
    m = generate_g(message);

    vector<int>y1, y2;
    y1 = multiply(g1, m);
    y2 = multiply(g2, m);

    sort(y1.begin(), y1.end());
    sort(y2.begin(), y2.end());

    printv(y1);
    printv(y2);

    int mexlen = max(*(y1.end()-1), *(y2.end()-1));

    int code1[mexlen+1] = {0}, code2[mexlen+1] = {0};

    for(i=0; i<y1.size(); i++)
    {
        code1[y1[i]]^=1;
    }
    for(int i=0;i<=mexlen;i++){
        cout<<code1[i]<<" "<<y1[i]<<endl;
    }
    cout<<endl<<endl;
    for(i=0; i<y2.size(); i++)
    {
        code2[y2[i]]^=1;
    }
    for(int i=0;i<mexlen;i++){
        cout<<code2[i]<<" "<<y2[i]<<endl;
    }
    for(int i=0; i<=mexlen; i++)
    {
        cout<<code1[i]<<code2[i]<<" ";
    }
    cout<<endl;
}



clc;
close all;
clear all;
p=(.01: .01: 1);
H=p.*log2(1./p)+(1-p).*log2(1./(1-p));
plot(p, H);


