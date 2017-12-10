vector <string> hashTable[20];
    int hashTableSize=20;

// Insert

    void insert(string s)
    {
                // Compute the index using Hash Function
        int index = hashFunc(s);
        // Insert the element in the linked list at the particular index
        hashTable[index].push_back(s);
    }

// Search

     void search(string s)
    {
        //Compute the index by using the hash function
        int index = hashFunc(s);
        //Search the linked list at that specific index
        for(int i = 0;i < hashTable[index].size();i++)
        {
            if(hashTable[index][i] == s)
            {
                cout << s << " is found!" << endl;
                return;
            }
        }
        cout << s << " is not found!" << endl;
    }