void print_less(string a, string b, string c){
    std::cout << ((a <= b) ? (a <= c) ? a : (b <= c) ? b : c : c) << std::endl;
}