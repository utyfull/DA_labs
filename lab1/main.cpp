#include <iostream>
#include <string>
#include <vector>
#include <string_view>

void countingSortByChar(const std::vector<std::string_view>& arr,
                        std::vector<std::string_view>& output, int pos) {
    int n = arr.size();
    int count[128] = {0};
    output.resize(n);

    for (int i = 0; i < n; i++) {
        char ch = arr[i][pos];
        count[(int)ch]++;
    }
    for (int i = 1; i < 128; i++) {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        char ch = arr[i][pos];
        output[--count[(int)ch]] = arr[i];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string buffer;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (!line.empty()) {
            buffer += line;
            buffer.push_back('\n');
        }
    }
    
    std::vector<std::string_view> lines;
    size_t start = 0;
    while (true) {
        size_t pos = buffer.find('\n', start);
        if (pos == std::string::npos) break;
        lines.push_back(std::string_view(buffer.data() + start, pos - start));
        start = pos + 1;
    }
    
    int positions[] = {7, 6, 4, 3, 2, 0};
    const int numPositions = sizeof(positions) / sizeof(positions[0]);
    
    std::vector<std::string_view> output;
    for (int i = 0; i < numPositions; i++) {
        countingSortByChar(lines, output, positions[i]);
        lines.swap(output);
    }
    
    for (const auto& sv : lines) {
        std::cout << sv << "\n";
    }
    
    return 0;
}
