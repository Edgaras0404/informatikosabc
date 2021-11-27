#include <iostream>
#include <fstream>

void input ( int &n, std::string lName[], std::string fName[], char gender[], int year[], int month[], int day[] ) {
    std::ifstream in("Gimstamumas.txt");
    in >> n;
    for (int i = 0; i < n; i++)
    {
        in.ignore(80, '\n');
        char name[13];
        in.read(name, 12);
        lName[i] = name;
        in.ignore(1,'\n');
        in.read(name, 12);
        fName[i] = name;
        in >> gender[i] >> year[i] >> month[i] >> day[i];
    }

    in.close(); 
}

void count ( int &males, int &females, char gender[], int n ) {

    for (int i = 0; i < n; i++)
    {
        if (gender[i] == 'v')
        {
            males++; 
        } else if (gender[i] == 'm')
        {
            females++;
        }
         
    }
}

void findPopNames( std::string &mpfName, std::string &mpmName, int &mpfC, int &mpmC, char gender[], std::string fName[], int n ) {

    for (int i = 0; i < n; i++)
    {
        int reocc = 0;
        for (int j = 0; j < n; j++)
        {
            if (fName[i] == fName[j])
            {
                reocc++; 
            }
        }
        if (gender[i] == 'v')
        {
            if (reocc > mpmC)
            {
                mpmC = reocc;
                mpmName = fName[i];
            } else if (reocc == mpmC)
            {
                if (mpmName > fName[i])
                {
                    mpmName = fName[i]; 
                }
            }
        } else {
            if (reocc > mpfC)
            {
                mpfC = reocc;
                mpfName = fName[i];
            } else if (reocc == mpfC) {
                if (mpfName > fName[i])
                {
                    mpfName = fName[i]; 
                }
            }
        }
    }

}


int main () {
    int n;  
    std::string fName[10000];
    std::string lName[10000];
    char gender[10000];
    int year[10000];
    int month[10000];
    int day[10000];

    input ( n, lName, fName, gender, year, month, day );

    int males = 0, females = 0;
    count( males, females, gender, n);

   
    std::string mpfName, mpmName;
    int mpfC = 0, mpmC = 0;

    findPopNames(mpfName, mpmName, mpfC, mpmC, gender, fName, n ); 
    

    int months[12] = { 0 };
    for (int i = 0; i < 12; i++)
    {
        months[month[i]-1]++;
    }

    std::ofstream out("Rezgimstamumas.txt");
    out << "Berniukai: " << males << std::endl;
    out << mpmName << std::endl;
    out << "Mergaites: " << females << std::endl;
    out << mpfName << std::endl;
    for (int i = 0; i < 12; i++)
    {
        out << months[i] << " ";
    }
    out << std::endl;  
    out.close(); 
    return 0;
}