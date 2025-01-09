int main() {
    vector<int> arr = {1, 2, 3, 5, 5, 7, 9};
    int value = 5;
    auto it = upper_bound(arr.begin(), arr.end(), value);
    auto it = lower_bound(arr.begin(), arr.end(), value);

    if (it != arr.end()) {
        std::cout << "Upper bound of " << value << " is at index " 
                  << (it - arr.begin()) << " with value " << *it << std::endl;
    } else {
        cout << "Upper bound not found.\n";
    }

    return 0;
}

it ->>> gives index;
and it-arr.begin()  gives index  starting index ,arr.end()  given ending index;
*it gives value;