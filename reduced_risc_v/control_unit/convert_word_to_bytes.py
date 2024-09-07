def split_bytes_modified(lines):
    processed_lines = []
    for line in lines:
        line = line.strip()
        chunks = [line[i:i+2] for i in range(len(line) - 2, -2, -2)]
        formatted_line = "\n".join(chunks) + "\n"
        processed_lines.append(formatted_line)
    #change path to the one to write to
    with open("C:/Users/bruno/PycharmProjects/pythonProject3/machinecodebyte.mem", 'w') as out_file:
        out_file.write("".join(processed_lines))
    return processed_lines

def read_file_to_list(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()
    lines = [line.strip() for line in lines]
    return lines

#change the path to the one to read from
file_path = 'C:/Users/bruno/PycharmProjects/pythonProject3/machinecode.mem'
lines_from_file = read_file_to_list(file_path)
split_bytes_output_modified = split_bytes_modified(lines_from_file)
