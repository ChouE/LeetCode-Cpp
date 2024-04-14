#include <iostream>
#include <string>
#include <vector>

std::vector<int> KMPPreprocess(const std::string& pattern) {
    std::vector<int> lsp(pattern.size());
    int j = 0; 
    lsp[0] = 0;
    for (int i = 1; i < pattern.size(); ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = lsp[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        lsp[i] = j;
    }
    return lsp;
}

std::vector<int> KMP(const std::string& text, const std::string& pattern) {
    std::vector<int> lsp = KMPPreprocess(pattern);
    std::vector<int> matches;
    int j = 0; 
    for (int i = 0; i < text.size(); i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = lsp[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
            if (j == pattern.size()) {
                matches.push_back(i - j + 1);
                j = lsp[j - 1];
            }
        } else {
            j = 0;
        }
    }
    return matches;
}

int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";
    std::vector<int> matches = KMP(text, pattern);

    std::cout << "Pattern found at index: ";
    for (int index : matches) {
        std::cout << index << ' ';
    }
    return 0;
}