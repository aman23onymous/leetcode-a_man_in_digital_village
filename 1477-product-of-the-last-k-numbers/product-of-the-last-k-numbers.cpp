class ProductOfNumbers {
public:
    vector<int> prefixProduct;
    
    ProductOfNumbers() {
        prefixProduct.push_back(1);  // Initialize with 1 to handle product of the first element
    }
    
    void add(int num) {
        if (num == 0) {
            // If num is 0, reset the prefixProduct
            prefixProduct.clear();
            prefixProduct.push_back(1);
        } else {
            // Otherwise, add the product to the prefixProduct
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefixProduct.size();
        if (k >= n) return 0; // If k exceeds or equals the size of the array, a zero must have been added within the last k elements
        return prefixProduct[n-1] / prefixProduct[n-k-1];
    }
};
