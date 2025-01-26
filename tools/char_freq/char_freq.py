import os
import re
import argparse
from collections import Counter
from tabulate import tabulate

def find_special_characters(file_content):
    return re.findall(r'[^a-zA-Z0-9\s]', file_content)

def find_numeric_characters(file_content):
    return re.findall(r'\d', file_content)

def find_alpha_characters(file_content):
    return re.findall(r'[a-zA-Z]', file_content)

def find_bigrams(file_content):
    return [file_content[i:i+2] for i in range(len(file_content) - 1) 
            if re.search(r'[a-zA-Z]', file_content[i]) and 
               re.search(r'[a-zA-Z]', file_content[i+1])]

def find_numeric_bigrams(file_content):
    return [file_content[i:i+2] for i in range(len(file_content) - 1) 
            if re.search(r'\d', file_content[i]) and 
               re.search(r'\d', file_content[i+1])]

def find_special_bigrams(file_content):
    return [file_content[i:i+2] for i in range(len(file_content) - 1) 
            if re.search(r'[^a-zA-Z0-9\s]', file_content[i]) and 
               re.search(r'[^a-zA-Z0-9\s]', file_content[i+1])]

def find_trigrams(file_content):
    return [file_content[i:i+3] for i in range(len(file_content) - 2) 
            if re.search(r'[a-zA-Z]', file_content[i]) and 
               re.search(r'[a-zA-Z]', file_content[i+1]) and 
               re.search(r'[a-zA-Z]', file_content[i+2])]

def find_numeric_trigrams(file_content):
    return [file_content[i:i+3] for i in range(len(file_content) - 2) 
            if re.search(r'\d', file_content[i]) and 
               re.search(r'\d', file_content[i+1]) and 
               re.search(r'\d', file_content[i+2])]

def find_special_trigrams(file_content):
    return [file_content[i:i+3] for i in range(len(file_content) - 2) 
            if re.search(r'[^a-zA-Z0-9\s]', file_content[i]) and 
               re.search(r'[^a-zA-Z0-9\s]', file_content[i+1]) and 
               re.search(r'[^a-zA-Z0-9\s]', file_content[i+2])]

def process_files(directory, extensions):
    alpha_char_counter = Counter()
    numeric_char_counter = Counter()
    special_char_counter = Counter()
    
    bigram_counter = Counter()
    numeric_bigram_counter = Counter()
    special_bigram_counter = Counter()
    
    trigram_counter = Counter()
    numeric_trigram_counter = Counter()
    special_trigram_counter = Counter()

    # Loop through the directory and process files based on the specified extensions
    for subdir, _, files in os.walk(directory):
        for file in files:
            # Check if the file has a specified extension
            if file.endswith(tuple(extensions)):
                file_path = os.path.join(subdir, file)
                with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                    content = f.read()
                    # Update counters with characters, bigrams, and trigrams found in the content
                    alpha_char_counter.update(find_alpha_characters(content))
                    numeric_char_counter.update(find_numeric_characters(content))
                    special_char_counter.update(find_special_characters(content))
                    
                    bigram_counter.update(find_bigrams(content))
                    numeric_bigram_counter.update(find_numeric_bigrams(content))
                    special_bigram_counter.update(find_special_bigrams(content))
                    
                    trigram_counter.update(find_trigrams(content))
                    numeric_trigram_counter.update(find_numeric_trigrams(content))
                    special_trigram_counter.update(find_special_trigrams(content))

    return (alpha_char_counter, numeric_char_counter, special_char_counter,
            bigram_counter, numeric_bigram_counter, special_bigram_counter,
            trigram_counter, numeric_trigram_counter, special_trigram_counter)

def main(directory, extensions):
    (alpha_char_counter, numeric_char_counter, special_char_counter, 
     bigram_counter, numeric_bigram_counter, special_bigram_counter, 
     trigram_counter, numeric_trigram_counter, special_trigram_counter) = process_files(directory, extensions)
    
    # Combine data for three main tables
    tables = {
        "Special Characters": [
            ("Single Special Characters", special_char_counter.most_common(10)),
            ("Bigrams of Special Characters", special_bigram_counter.most_common(10)),
            ("Trigrams of Special Characters", special_trigram_counter.most_common(10)),
        ],
        "Numeric Characters": [
            ("Single Numeric Characters", numeric_char_counter.most_common(10)),
            ("Bigrams of Numeric Characters", numeric_bigram_counter.most_common(10)),
            ("Trigrams of Numeric Characters", numeric_trigram_counter.most_common(10)),
        ],
        "Alphabetic Characters": [
            ("Single Alphabetic Characters", alpha_char_counter.most_common(10)),
            ("Bigrams of Alphabetic Characters", bigram_counter.most_common(10)),
            ("Trigrams of Alphabetic Characters", trigram_counter.most_common(10)),
        ]
    }

    for title, data in tables.items():
        combined_data = []
        for sub_title, entries in data:
            combined_data.append([f"{sub_title}"] + [""] * (2 - len(entries)))  # Header row
            combined_data.extend([(entry[0], entry[1]) for entry in entries])
        
        print(f"\n{title}:\n")
        print(tabulate(combined_data, headers=["Character(s)", "Count"], tablefmt="grid"))

if __name__ == '__main__':
    # Set up argument parsing for command line execution
    parser = argparse.ArgumentParser(description="Analyze files for character statistics.")
    parser.add_argument("directory", type=str, help="The directory to search for files.")
    parser.add_argument("--extensions", type=str, nargs='*', default=['.java'], 
                        help="List of file extensions to search for (default: .java).")
    args = parser.parse_args()

    main(args.directory, args.extensions)

