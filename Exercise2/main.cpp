#include <iostream>
#include <fstream>

int main()
{
    std::string fileNameIn = "data.csv";
    std::string fileNameOut = "result.csv";
    std::ifstream ifstr(fileNameIn);
    std::ofstream ofstr(fileNameOut);

    if (ifstr.fail())
    {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    if(ofstr.fail())
    {
        std::cerr << "Failed to open output file." << std::endl;
        return 1;
    }

    long double val = 0;
    long double new_val = 0;
    long double sum = 0;
    int counter = 0;
    long double mean = 0;
    ofstr << "# N Mean" << std::endl;

    while (ifstr >> val)
    {
        new_val = (3./4. * val) - 7./4.;
        //per mappare punti dall'intervallo [1,5] all'intervallo [-1,2] scelgo la funzione affine passante per (1,-1) e (5,2): y=3/4*x-7/4
        sum += new_val;
        counter++;
        mean = sum/counter;

        ofstr << counter << " " << std::scientific << mean << "\n";

    }

    std::cout << "Results have been written to result.csv." << std::endl;

    ifstr.close();
    ofstr.close();
    return 0;
}

