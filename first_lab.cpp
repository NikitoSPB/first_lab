#include <iostream>
#include <fstream>
#include <string>
#define sizeBaza 100
#define maxGroup 4

using namespace std;

char nameBaza[100] = "C:\\Users\\TPAHCFOPMATOP\\Documents\\Программирование\\2 сем\\first_lab\\bazaStudents.txt";
char nameIdzBaza[100] = "C:\\Users\\TPAHCFOPMATOP\\Documents\\Программирование\\2 сем\\first_lab\\idzVolley.txt";

struct Student
{
    string fio;
    char sex;
    int group = 0;
    int id;
    int marksExam[8];
    float GPA = 0;
    string formEducation;
};

struct idzVolley
{
    string Fio;
    char Sex;
    int age = 0;
    string size;
    string category;
    int year;
};

void fileCorrect(Student* fcStudents, int fcCountSt)
{
    ofstream File;
    File.open(nameBaza);
    if (!File.is_open())
    {
        cout << "File not open! Error! \n";
        exit(1);
    }
    for (int i = 0; i < fcCountSt; i++)
    {
        File << fcStudents[i].fio << '\n';
        File << fcStudents[i].sex << '\n';
        File << fcStudents[i].group << '\n';
        File << fcStudents[i].id << '\n';
        for (int j = 0; j < 7; j++)
            File << fcStudents[i].marksExam[j] << ' ';
        File << fcStudents[i].marksExam[7] << '\n';
        File << fcStudents[i].formEducation;
        if (i != (fcCountSt - 1))
            File << "\n\n";
    }
    File.close();
}

void coutStudent(Student* csStudents, int num_student)
{
    cout << csStudents[num_student].fio << '\n'
        << csStudents[num_student].sex << '\n'
        << csStudents[num_student].group << '\n'
        << csStudents[num_student].id << '\n';
    for (int i = 0; i < 8; i++)
        cout << csStudents[num_student].marksExam[i] << ' ';
    cout << '\n';
    cout << csStudents[num_student].formEducation << '\n';
}

int f_countStudents(Student* fcsStudents)
{
    int count = 0;
    for (int i = 0; fcsStudents[i].group != 0 && i < sizeBaza; i++)
        count++;
    return count;
}

void sortStudents(Student* ssStudents, int ssCountSt)
{
    for (int i = 1; i < ssCountSt; i++)
    {
        Student ssStudent = ssStudents[i];
        int pos = i;
        for (int j = i - 1; j >= 0 && ssStudents[j].group > ssStudent.group; j--)
        {
            ssStudents[j + 1] = ssStudents[j];
            pos--;
        }
        for (int j = pos - 1; (j >= 0) && (ssStudents[j].id > ssStudent.id) && (ssStudents[j].group == ssStudent.group); j--)
        {
            ssStudents[j + 1] = ssStudents[j];
            pos--;
        }
        ssStudents[pos] = ssStudent;
    }
}

void checkGroup(Student* cgStudents, int num_group, int cgCountSt)
{
    int countStGroup = 0;
    for (int i = 0; i < cgCountSt && countStGroup < maxGroup; i++)
    {
        if (cgStudents[i].group == num_group)
            countStGroup++;
    }
    if (countStGroup < maxGroup)
        return;
    if (countStGroup >= maxGroup)
    {
        cgStudents[cgCountSt].group++;
        checkGroup(cgStudents, cgStudents[cgCountSt].group, cgCountSt);
    }
    cout << "The group is full. New number: " << cgStudents[cgCountSt].group << '\n';
}

void addId(Student* aiStudents, int aiCountSt)
{
    string aiFIO = aiStudents[aiCountSt].fio;
    int groupID = 1;
    for (int i = 0; i < aiCountSt; i++)
    {
        if (aiStudents[aiCountSt].group == aiStudents[i].group)
        {
            groupID++;
            int j = 0;
            for (j; j < aiFIO.length();j++)
            {
                if (aiFIO[j] != aiStudents[i].fio[j])
                    break;
            }
            if ((j != aiFIO.length()) && (aiFIO[j] < aiStudents[i].fio[j]))
            {
                aiStudents[aiCountSt].id = aiStudents[i].id;
                for (int h = i; h < aiCountSt; h++)
                    aiStudents[h].id++;
                return;
            }
        }
    }
    aiStudents[aiCountSt].id = groupID;
}

void f_GPA(Student* gpaStudents, int gpaCountSt)
{
    for (int i = 0; i < gpaCountSt; i++)
    {
        float gpa = 0;
        for (int j = 0; j < 8; j++)
            gpa += gpaStudents[i].marksExam[j];
        gpa /= 8;
        gpaStudents[i].GPA = gpa;
    }
}

void newStudent(Student* nsStudents, int nsCountSt)
{
    if (nsCountSt >= sizeBaza)
    {
        cout << "The base is full\n";
        system("Pause");
        return;
    }
    cout << "Input FIO\n";
    cin.ignore();
    getline(cin, nsStudents[nsCountSt].fio);
    cout << "Input sex: ""M"" or ""F""\n";
    cin >> nsStudents[nsCountSt].sex;
    cout << "Input group\n";
    cin >> nsStudents[nsCountSt].group;
    checkGroup(nsStudents, nsStudents[nsCountSt].group, nsCountSt);
    addId(nsStudents, nsCountSt);
    cout << "Input marks of exams\n";
    for (int i = 0; i < 8; i++)
        cin >> nsStudents[nsCountSt].marksExam[i];
    cout << "Input form of education\n";
    cin >> nsStudents[nsCountSt].formEducation;
    /*cout << nSstudents[countStudents].fio << '\n'
        << nSstudents[countStudents].sex << '\n'
        << nSstudents[countStudents].group << '\n';
    for (int i = 0; i < 8; i++)
        cout << nSstudents[countStudents].marksExam[i] << ' ';
    cout << '\n';
    for (int i = 0; i < 9; i++)
        cout << nSstudents[countStudents].formEducation[i];
    cout << '\n';
    cout << nSstudents[countStudents].date << '\n';
    */
}

void correctBaza(Student* cbStudents, int number_note)
{
    int punktCorrectMenu;
    system("cls");
    cout << cbStudents[number_note].fio << '\n'
        << cbStudents[number_note].sex << '\n'
        << cbStudents[number_note].group << '\n';
    for (int i = 0; i < 8; i++)
        cout << cbStudents[number_note].marksExam[i] << ' ';
    cout << '\n';
    cout << cbStudents[number_note].formEducation << '\n';
    cout << "\nWhich information you want to correct? Choose the number\n"
        << "1 - FIO\n"
        << "2 - Sex\n"
        << "3 - Number of group\n"
        << "4 - Marks of exams\n"
        << "5 - Form of education\n"
        << "0 - Nothing\n\n";
    cin >> punktCorrectMenu;
    system("cls");
    switch (punktCorrectMenu)
    {
    case 1:
        cout << "Input new FIO\n";
        cin >> cbStudents[number_note].fio;
        cout << "New note:\n";
        coutStudent(cbStudents, number_note);
        system("Pause");
        break;
    case 2:
        cout << "Input new sex\n";
        cin >> cbStudents[number_note].sex;
        cout << "New note:\n";
        coutStudent(cbStudents, number_note);
        system("Pause");
        break;
    case 3:
        cout << "Input new number of group\n";
        cin >> cbStudents[number_note].group;
        cout << "New note:\n";
        coutStudent(cbStudents, number_note);
        system("Pause");
        break;
    case 4:
        cout << "Input new marks of exams\n";
        for (int i = 0; i < 8; i++)
            cin >> cbStudents[number_note].marksExam[i];
        cout << "New note:\n";
        coutStudent(cbStudents, number_note);
        system("Pause");
        break;
    case 5:
        cout << "Input new form of education\n";
        cin >> cbStudents[number_note].formEducation;
        cout << "\nNew note:\n";
        coutStudent(cbStudents, number_note);
        system("Pause");
        break;
    case 0:
        break;
    default:
        cout << "Error! Repeat, please.\n\n";
        system("Pause");
        correctBaza(cbStudents, number_note);
        break;
    }
}

void coutStudents(Student* cssStudents, int csCountSt)
{
    for (int i = 0; i < csCountSt; i++)
    {
        coutStudent(cssStudents, i);
        cout << '\n';
    }
}

void searchGroup(Student *sgStudents, int sgNum_gr, int sgCountSt)
{
    int flag_group = 0;
    for (int i = 0; i < sgCountSt; i++)
    {
        if (sgStudents[i].group == sgNum_gr)
        {
            coutStudent(sgStudents, i);
            flag_group++;
            cout << '\n';
        }
    }
    if (!flag_group)
    {
        cout << "Group not found.\n\n";
        system("Pause");
        return;
    }
    system("Pause");
}

void top_students(Student* tsStudents, int tsCountSt)
{
    for (int i = 1; i < tsCountSt; i++)
    {
        Student tsStudent = tsStudents[i];
        int pos = i;
        for (int j = i - 1; j >= 0 && tsStudents[j].GPA < tsStudent.GPA; j--)
        {
            tsStudents[j + 1] = tsStudents[j];
            pos--;
        }
        tsStudents[pos] = tsStudent;
    }
    for (int i = 0; i < tsCountSt; i++)
    {
        cout << tsStudents[i].fio << '\n'
            << tsStudents[i].sex << '\n'
            << tsStudents[i].group << '\n';
        for (int j = 0; j < 8; j++)
            cout << tsStudents[i].marksExam[j] << ' ';
        cout << '\n';
        cout << tsStudents[i].GPA << '\n';
        cout << tsStudents[i].formEducation << '\n';
        cout << '\n';
    }
}

void countMF(Student* cmfStudents, int cmfCountSt)
{
    int countM = 0, countF = 0;
    for (int i = 0; i < cmfCountSt; i++)
    {
        if (cmfStudents[i].sex == 'M')
            countM++;
        else if (cmfStudents[i].sex == 'F')
            countF++;
    }
    cout << "In base information about " << countM << " mens and " << countF << " womans.\n";
    system("Pause");
}

void cout3Students(Student* c3Students, int c3CountSt)
{
    for (int i = 0; i < c3CountSt; i++)
    {
        int j = 0;
        for (j; j < 8; j++)
        {
            if (c3Students[i].marksExam[j] == 3)
                break;
        }
        if (j != 8)
        {
            coutStudent(c3Students, i);
            cout << '\n';
        }
    }
    system("Pause");
}

void cout4Students(Student* c4Students, int c4CountSt)
{
    for (int i = 0; i < c4CountSt; i++)
    {
        int j = 0, sum = 0;
        for (j; j < 8; j++)
        {
            if (c4Students[i].marksExam[j] == 3)
                break;
            sum += c4Students[i].marksExam[j];
        }
        if ((j == 8) && (sum / 8 != 5))
        {
            coutStudent(c4Students, i);
            cout << '\n';
        }
    }
    system("Pause");
}

void cout5Students(Student* c5Students, int c5CountSt)
{
    for (int i = 0; i < c5CountSt; i++)
    {
        int j = 0;
        for (j; j < 8; j++)
        {
            if ((c5Students[i].marksExam[j] == 3) || (c5Students[i].marksExam[j] == 4))
                break;
        }
        if (j == 8)
        {
            coutStudent(c5Students, i);
            cout << '\n';
        }
    }
    system("Pause");
}

void coutIdStudent(Student* cisStudents, int cisK, int cisCountSt)
{
    int flagID = 0, i = cisK - 1;
    while (i < cisCountSt)
    {
        if (cisStudents[i].id == cisK)
        {
            flagID++;
            coutStudent(cisStudents, i);
            cout << '\n';
            i += cisK;
            continue;
        }
        if (cisStudents[i].id > cisK)
            i += cisK;
        else
        {
            i = i + (cisK - cisStudents[i].id);
        }
    }
    if (!flagID)
        cout << "Students not found\n";
    system("Pause");
}

int idzF_countStudents(idzVolley* idzfcsStudents)
{
    int count = 0;
    for (int i = 0; idzfcsStudents[i].age != 0 && i < sizeBaza; i++)
        count++;
    return count;
}

void idzCoutStudent(idzVolley* idzcsStudents, int idzNum_student)
{
    cout << idzcsStudents[idzNum_student].Fio << '\n'
        << idzcsStudents[idzNum_student].Sex << '\n'
        << idzcsStudents[idzNum_student].age << '\n'
        << idzcsStudents[idzNum_student].size << '\n'
        << idzcsStudents[idzNum_student].category << '\n'
        << idzcsStudents[idzNum_student].year << '\n';
}

void idzCategoryStudents(idzVolley* idzcsStudents, int idzcsCountSt)
{
    int flag = 0;
    for (int i = 0; i < idzcsCountSt; i++)
    {
        if (idzcsStudents[i].category == "yes")
        {
            flag++;
            idzCoutStudent(idzcsStudents, i);
            cout << '\n';
        }
    }
    if (!flag)
        cout << "Students not found!\n";
    system("Pause");
}

void idzWomanStudents(idzVolley* idzwsStudents, int idzwsCountSt)
{
    int flag = 0;
    for (int i = 0; i < idzwsCountSt; i++)
    {
        if (idzwsStudents[i].Sex == 'F')
        {
            flag++;
            idzCoutStudent(idzwsStudents, i);
            cout << '\n';
        }
    }
    if (!flag)
        cout << "Students not found!\n";
    system("Pause");
}

void idzCourseStudents(idzVolley* idzCsStudents, int idzCsCountSt, int Num_year)
{
    int flag = 0;
    for (int i = 0; i < idzCsCountSt; i++)
    {
        if (idzCsStudents[i].year == Num_year)
        {
            flag++;
            idzCoutStudent(idzCsStudents, i);
            cout << '\n';
        }
    }
    if (!flag)
        cout << "Students not found!\n";
    system("Pause");

}

void idzMenClothesStudents(idzVolley* idzmcsStudents, int idzmcsCountSt)
{
    int flag = 0;
    for (int i = 0; i < idzmcsCountSt; i++)
    {
        if ((idzmcsStudents[i].Sex == 'M') && ((idzmcsStudents[i].size != "XS") && (idzmcsStudents[i].size != "S")))
        {
            flag++;
            idzCoutStudent(idzmcsStudents, i);
            cout << '\n';
        }
    }
    if (!flag)
        cout << "Students not found!\n";
    system("Pause");
}

void idzMenu(idzVolley* idzmStudents)
{
    system("cls");
    int idzPunktMenu;
    int idzCountStudents = idzF_countStudents(idzmStudents);
    cout << "Which action from IDZ you want to make? Choose the number\n"
        << "1 - Output students with category\n"
        << "2 - Output woman students\n"
        << "3 - Output students from one course\n"
        << "4 - Output man students with size more than S\n"
        << "0 - Exit\n\n";
    cin >> idzPunktMenu;
    system("cls");
    switch (idzPunktMenu)
    {
    case 1:
        if (idzCountStudents == 0)
        {
            cout << "No information in base. At first add students.\n";
            system("Pause");
            system("cls");
            break;
        }
        idzCategoryStudents(idzmStudents, idzCountStudents);
        idzMenu(idzmStudents);
        break;
    case 2:
        if (idzCountStudents == 0)
        {
            cout << "No information in base. At first add students.\n";
            system("Pause");
            system("cls");
            break;
        }
        idzWomanStudents(idzmStudents, idzCountStudents);
        idzMenu(idzmStudents);
        break;
    case 3:
        if (idzCountStudents == 0)
        {
            cout << "No information in base. At first add students.\n";
            system("Pause");
            system("cls");
            break;
        }
        int numberCourse;
        while (true)
        {
            cout << "\nWhich course you want to check?\n";
            cin >> numberCourse;
            if (numberCourse > 0 && numberCourse < 7)
            {
                idzCourseStudents(idzmStudents, idzCountStudents, numberCourse);
                break;
            }
            cout << "Error. Repeat, please\n";
            cin.clear();
            while (cin.get() != '\n');
            system("Pause");
            system("cls");
        }
        idzMenu(idzmStudents);
        break;
    case 4:
        if (idzCountStudents == 0)
        {
            cout << "No information in base. At first add students.\n";
            system("Pause");
            system("cls");
            break;
        }
        idzMenClothesStudents(idzmStudents, idzCountStudents);
        idzMenu(idzmStudents);
        break;
    case 0:
        break;
    default:
        cout << "Error! Repeat, please.\n\n";
        system("Pause");
        idzMenu(idzmStudents);
        break;
    }
}

void idz()
{
    idzVolley massVolley[sizeBaza];
    ifstream File;
    File.open(nameIdzBaza);
    if (!File.is_open())
    {
        cout << "File not open! Error! \n";
        exit(1);
    }
    for (int i = 0; !File.eof(); i++)
    {
        /*
        string fio;
        char sex;
        int age = 0;
        string size;
        bool category;
        int year;
        */
        if (i != 0)
        {
            getline(File, massVolley[i].Fio);
            getline(File, massVolley[i].Fio);
        }
        getline(File, massVolley[i].Fio);
        File >> massVolley[i].Sex;
        File >> massVolley[i].age;
        getline(File, massVolley[i].size);
        getline(File, massVolley[i].size);
        getline(File, massVolley[i].category);
        File >> massVolley[i].year;
    }
    File.close();
    idzMenu(massVolley);
}

void menu(Student *mstudents)
{
    system("cls");
    int punktMenu;
    int countStudents = f_countStudents(mstudents);
    cout << "Which action with base you want to make? Choose the number\n"
        << "1 - Add new student\n"
        << "2 - Correct note\n"
        << "3 - Output all students\n"
        << "4 - Output group students\n"
        << "5 - Output best students\n"
        << "6 - Count of mens and womans\n"
        << "7 - Output students without stipend\n"
        << "8 - Output students without ""3""\n"
        << "9 - Output students without ""3"" and ""4""\n"
        << "10 - Output student by id\n"
        << "11 - Idz\n"
        << "0 - Exit\n\n";
    cin >> punktMenu;
    system("cls");
    switch (punktMenu)
    {
    case 1:
        newStudent(mstudents, countStudents);
        countStudents = f_countStudents(mstudents);
        sortStudents(mstudents, countStudents);
        fileCorrect(mstudents, countStudents);
        menu(mstudents);
        break;
    case 2:
        if (countStudents == 0)
        {
            cout << "No information in base. At first add students.\n";
            system("Pause");
            system("cls");
            menu(mstudents);
            break;
        }
        int id_correct;
        while (true)
        {
            cout << "\nWhich note you want to correct?\n";
            cin >> id_correct;
            if (id_correct >= 1 && id_correct <= countStudents)
            {
                correctBaza(mstudents, id_correct - 1);
                break;
            }
            cout << "Note not found. Repeat, please\n";
            cin.clear();
            while (cin.get() != '\n');
            system("Pause");
            system("cls");
        }
        sortStudents(mstudents, countStudents);
        fileCorrect(mstudents, countStudents);
        menu(mstudents);
        break;
    case 3:
        if (countStudents == 0)
        {
            cout << "No information in base. At first add students.\n";
            system("Pause");
            system("cls");
            menu(mstudents);
            break;
        }
        coutStudents(mstudents, countStudents);
        system("Pause");
        menu(mstudents);
        break;
    case 4:
        if (countStudents == 0)
        {
            cout << "No information in base. At first add students.\n";
            system("Pause");
            system("cls");
            menu(mstudents);
            break;
        }
        int numberGroup;
        while (true)
        {
            cout << "\nWhich group you want to check?\n";
            cin >> numberGroup;
            if (numberGroup > 0)
            {
                searchGroup(mstudents, numberGroup, countStudents);
                break;
            }
            cout << "Error. Repeat, please\n";
            system("Pause");
            cin.clear();
            while (cin.get() != '\n');
            system("cls");
        }
        menu(mstudents);
        break;
    case 5:
        if (countStudents == 0)
        {
            cout << "No information in base. At first add students.\n";
            system("Pause");
            system("cls");
            menu(mstudents);
            break;
        }
        f_GPA(mstudents, countStudents);
        top_students(mstudents, countStudents);
        system("Pause");
        sortStudents(mstudents, countStudents);
        fileCorrect(mstudents, countStudents);
        menu(mstudents);
        break;
    case 6:
        if (countStudents == 0)
        {
            cout << "No information in base. At first add students.\n";
            system("Pause");
            system("cls");
            menu(mstudents);
            break;
        }
        countMF(mstudents, countStudents);
        menu(mstudents);
        break;
    case 7:
        if (countStudents == 0)
        {
            cout << "No information in base. At first add students.\n";
            system("Pause");
            system("cls");
            menu(mstudents);
            break;
        }
        cout3Students(mstudents, countStudents);
        menu(mstudents);
        break;
    case 8:
        if (countStudents == 0)
        {
            cout << "No information in base. At first add students.\n";
            system("Pause");
            system("cls");
            menu(mstudents);
            break;
        }
        cout4Students(mstudents, countStudents);
        menu(mstudents);
        break;
    case 9:
        if (countStudents == 0)
        {
            cout << "No information in base. At first add students.\n";
            system("Pause");
            system("cls");
            menu(mstudents);
            break;
        }
        cout5Students(mstudents, countStudents);
        menu(mstudents);
        break;
    case 10:
        if (countStudents == 0)
        {
            cout << "No information in base. At first add students.\n";
            system("Pause");
            system("cls");
            menu(mstudents);
            break;
        }
        int k;
        while (true)
        {
            cout << "\nWhich student you want to find?\n";
            cin >> k;
            if (k >= 1 && k <= maxGroup)
            {
                coutIdStudent(mstudents, k, countStudents);
                break;
            }
            cout << "Error. Repeat, please\n";
            cin.clear();
            while (cin.get() != '\n');
            system("Pause");
            system("cls");
        }
        menu(mstudents);
        break;
    case 11:
        idz();
        menu(mstudents);
        break;
    case 0:
        break;
    default:
        cout << "Error! Repeat, please.\n\n";
        system("Pause");
        menu(mstudents);
        break;
    }
}

int main(void)
{
	Student students[sizeBaza];
    ifstream File;
    File.open(nameBaza);
    if (!File.is_open())
    {
        cout << "File not open! Error! \n";
        return 0;
    }
    for (int i = 0; !File.eof(); i++)
    {
        if (i != 0)
            getline(File, students[i].fio);
        getline(File, students[i].fio);
        File >> students[i].sex;
        File >> students[i].group;
        File >> students[i].id;
        for (int j = 0; j < 8; j++)
            File >> students[i].marksExam[j];
        getline(File, students[i].formEducation);
        getline(File, students[i].formEducation);
    }
    File.close();
	menu(students);
    return 0;
}