intution 

[0,0,0,0,0] diff // take new array
(0,2,5)  // zero se 2 index that 5 ko add karo array me 
startung index par 5 kar do and (ending+1 < n) hai to -5 kar do 
[5,0,0,-5,0]  new diif
[5,5,5,0,0]  after cumulative sum arrag become like this ;

vector<int> prefix(m + 1, 0);
// Apply the difference array technique for range updates
for (auto& it : shifts) {
    int start = it[0];
    int end = it[1];
    int ele = it[2];
    // Increment or decrement based on the direction
    prefix[start] +=ele;
    if (end + 1 < arr.size()) {
        prefix[end + 1] -= ele;
    }
}