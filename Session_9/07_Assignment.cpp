#include <iostream>
#include <fstream>
#include <string>

void reverseFileLines(const std::string& inputPath, const std::string& outputPath) {
    std::ifstream inFile(inputPath, std::ios::binary);
    std::ofstream outFile(outputPath);

    if (!inFile || !outFile) {
        std::cerr << "Error opening files." << std::endl;
        return;
    }

    // Move to the end of the file
    inFile.seekg(0, std::ios::end);
    std::streampos fileSize = inFile.tellg();
    
    if (fileSize == 0) return; // Empty file

    std::streampos endPos = fileSize;
    std::streampos startPos;

    // Iterate backwards through the file byte by byte
    for (long long i = static_cast<long long>(fileSize) - 1; i >= 0; --i) {
        inFile.seekg(i);
        char ch;
        inFile.get(ch);

        // If we find a newline (and it's not the very last char of the file) 
        // or we've reached the very beginning of the file (i == 0)
        if ((ch == '\n' && i != static_cast<long long>(fileSize) - 1) || i == 0) {
            
            // Adjust start position: if at start of file, position is 0, 
            // otherwise it's the character right after the newline.
            startPos = (i == 0) ? 0 : (std::streampos)(i + 1);
            
            // Seek to the start of the line we just identified
            inFile.seekg(startPos);
            
            // Read forward from startPos to endPos and stream to output
            std::string line;
            std::getline(inFile, line);
            
            // Clean up carriage returns if on Windows (\r\n)
            if (!line.empty() && line.back() == '\r') {
                line.pop_back();
            }

            outFile << line << "\n";
            
            // The current 'i' becomes the new 'end' boundary for the next line up
            endPos = i;
        }
    }

    std::cout << "Lines reversed successfully." << std::endl;
    inFile.close();
    outFile.close();
}

int main() {
    reverseFileLines("input.txt", "output.txt");
    return 0;
}