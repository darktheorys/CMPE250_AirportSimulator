#include "Day.h"
#include "Person.h"
#include "BinaryHeap.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
#include "Simultaneity.h"

std::string st[8] = {"","","","","","","",""};

void case1(int luggage_counter, int security_counter, BinaryHeap *people){
    bool arrivalBased = true;
    bool vipPass = false;
    bool OTpass = false;
    int backup = people->currentSize;
    Day* day = new Day(luggage_counter, security_counter, people, arrivalBased, vipPass, OTpass);
    day->start();
    people->array = move(day->arrayBackup);
    people->currentSize = backup;
    people->buildHeap();
    std::stringstream ss;
    ss << (float) day->totalwait / (day->missed+day->boarded);
    ss<< " ";
    ss<< day->missed;
    st[0] = ss.str();
    delete day;
}

void case2(int luggage_counter, int security_counter, BinaryHeap* people){
    bool arrivalBased = false;
    bool vipPass = false;
    bool OTpass = false;
    int backup = people->currentSize;
    Day* day = new Day(luggage_counter, security_counter, people, arrivalBased, vipPass, OTpass);
    day->start();
    people->array = move(day->arrayBackup);
    people->currentSize = backup;
    people->buildHeap();
    std:: stringstream ss;
    ss << (float) day->totalwait / (day->missed+day->boarded);
    ss<< " ";
    ss<< day->missed;
    st[1] = ss.str();
    delete day;
}

void case3(int luggage_counter, int security_counter, BinaryHeap* people){
    bool arrivalBased = true;
    bool vipPass = true;
    bool OTpass = false;
    int backup = people->currentSize;
    Day* day = new Day(luggage_counter, security_counter, people, arrivalBased, vipPass, OTpass);
    day->start();
    people->array = move(day->arrayBackup);
    people->currentSize = backup;
    people->buildHeap();
    std::stringstream ss;
    ss << (float) day->totalwait / (day->missed+day->boarded);
    ss<< " ";
    ss<< day->missed;
    st[2] = ss.str();
    delete day;
}
void case4(int luggage_counter, int security_counter, BinaryHeap* people){
    bool arrivalBased = false;
    bool vipPass = true;
    bool OTpass = false;
    int backup = people->currentSize;
    Day* day = new Day(luggage_counter, security_counter, people, arrivalBased, vipPass, OTpass);
    day->start();
    people->array = move(day->arrayBackup);
    people->currentSize = backup;
    people->buildHeap();
    std::stringstream ss;
    ss << (float) day->totalwait / (day->missed+day->boarded);
    ss<< " ";
    ss<< day->missed;
    st[3] = ss.str();
    delete day;
}
void case5(int luggage_counter, int security_counter, BinaryHeap* people){
    bool arrivalBased = true;
    bool vipPass = false;
    bool OTpass = true;
    int backup = people->currentSize;
    Day* day = new Day(luggage_counter, security_counter, people, arrivalBased, vipPass, OTpass);
    day->start();
    people->array = move(day->arrayBackup);
    people->currentSize = backup;
    people->buildHeap();
    std::stringstream ss;
    ss << (float) day->totalwait / (day->missed+day->boarded);
    ss<< " ";
    ss<< day->missed;
    st[4] = ss.str();
    delete day;
}
void case6(int luggage_counter, int security_counter, BinaryHeap* people){
    bool arrivalBased = false;
    bool vipPass = false;
    bool OTpass = true;
    int backup = people->currentSize;
    Day* day = new Day(luggage_counter, security_counter, people, arrivalBased, vipPass, OTpass);
    day->start();
    people->array = move(day->arrayBackup);
    people->currentSize = backup;
    people->buildHeap();
    std::stringstream ss;
    ss << (float) day->totalwait / (day->missed+day->boarded);
    ss<< " ";
    ss<< day->missed;
    st[5] = ss.str();
    delete day;
}
void case7(int luggage_counter, int security_counter, BinaryHeap* people){
    bool arrivalBased = true;
    bool vipPass = true;
    bool OTpass = true;
    int backup = people->currentSize;
    Day* day = new Day(luggage_counter, security_counter, people, arrivalBased, vipPass, OTpass);
    day->start();
    people->array = move(day->arrayBackup);
    people->currentSize = backup;
    people->buildHeap();
    std::stringstream ss;
    ss << (float) day->totalwait / (day->missed+day->boarded);
    ss<< " ";
    ss<< day->missed;
    st[6] = ss.str();
    delete day;
}
void case8(int luggage_counter, int security_counter, BinaryHeap* people){
    bool arrivalBased = false;
    bool vipPass = true;
    bool OTpass = true;
    Day* day = new Day(luggage_counter, security_counter, people, arrivalBased, vipPass, OTpass);
    day->start();
    std::stringstream ss;
    ss << (float) day->totalwait / (day->missed+day->boarded);
    ss<< " ";
    ss<< day->missed;
    st[7] = ss.str();
    delete day;
    delete people;
}

template <class Container>
void split1(const std::string& str, Container& cont)
{
    std::istringstream iss(str);
    copy(std::istream_iterator<std::string>(iss),
         std::istream_iterator<std::string>(),
         back_inserter(cont));
}

int main(int argc, char* argv[]) {
    int luggage_counter = 0, security_counter = 0, board = 0, arrive = 0, secSpent = 0, lucSpent = 0;
    char hasvip, hasot;
    if (argc != 3) {
        return 1;
    }
    // here, perform the input operation. in other words,
    // read the file named <argv[1]>
    std::ifstream infile(argv[1]);
    std::string line;
    // process first line
    getline(infile, line);
    std::stringstream lineStream(line);
    int N = 0;
    lineStream >> N;
    if(N < 1 || N > 5000){
        return 1;
    }
    BinaryHeap* people = new BinaryHeap(N);
    lineStream >> luggage_counter;
    if(luggage_counter < 1 || luggage_counter > 20){
        return 1;
    }
    lineStream >> security_counter;
    if(security_counter < 1 || security_counter > 20){
        return 1;
    }
    for (int i=0; i<N; i++) {
        getline(infile, line);
        std::vector<std::string> words;
        split1(line,words);
        arrive = stoi(words[0]);
        board = stoi(words[1]);
        lucSpent = stoi(words[2]);
        secSpent = stoi(words[3]);
        hasvip = words[4][0];
        hasot = words[5][0];
        if(arrive < 1 || arrive > 50000){
            return 1;
        }
        if(board < 1 || board > 50000){
            return 1;
        }
        if(lucSpent < 1 || lucSpent > 50000){
            return 1;
        }
        if(secSpent < 1 || secSpent > 50000){
            return 1;
        }
        people->insert(new Person(arrive,board,lucSpent,secSpent,hasvip,hasot));
    }
    case1(luggage_counter, security_counter, people);
    case2(luggage_counter, security_counter, people);
    case3(luggage_counter, security_counter, people);
    case4(luggage_counter, security_counter, people);
    case5(luggage_counter, security_counter, people);
    case6(luggage_counter, security_counter, people);
    case7(luggage_counter, security_counter, people);
    case8(luggage_counter, security_counter, people);

    // print your results into the file named <argv[2]>
    std::ofstream myfile;
    myfile.open (argv[2]);
    myfile << st[0]<< std::endl << st[1]<< std::endl << st[2] << std::endl << st[3] <<std::endl << st[4]<<std::endl << st[5]<<std::endl << st[6]<<std::endl << st[7]; ;
    myfile.close();

    return 0;
}

