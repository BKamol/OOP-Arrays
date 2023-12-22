#include <iostream>
#include <fstream>
#include "List.h"
#include "SortedList.h"

using namespace std;

List<int> create_from_file(string filename)
{
    ifstream in(filename);

    List<int> l;
    int data;
    while (in >> data) l.add(data);
    
    in.close();

    return l;
}

List<int> l1_and_l2_minus_l3(List<int>& l1, List<int>& l2, List<int>& l3)
{
    List<int> result;
    int data;
    while (l1.get_p())
    {
        data = l1.get_value();
        if (l2.contains(data) && !l3.contains(data)) 
            result.add(data);
        l1.next();
    }

    return result;
}

List<int> copy_without_doubles(List<int>& l)
{
    List<int> result;
    int data;
    l.to_start();
    while (l.get_p())
    {
        data = l.get_value();
        if (!result.contains(data))
            result.add(data);
            
        l.next();
    }
    return result;
}

SortedList<int> creates_from_file(string filename)
{
    ifstream in(filename);

    SortedList<int> l;
    int data;
    while (in >> data) l.add(data);

    in.close();

    return l;
}

SortedList<int> l1_and_l2_minus_l3(SortedList<int>& l1, SortedList<int>& l2, SortedList<int>& l3)
{
    SortedList<int> result;
    int data;
    while (l1.get_p())
    {
        data = l1.get_value();
        if (l2.contains(data) && !l3.contains(data))
            result.add(data);
        l1.next();
    }

    return result;
}

SortedList<int> copy_without_doubles(SortedList<int>& l)
{
    SortedList<int> result;
    int data;
    l.to_start();
    while (l.get_p())
    {
        data = l.get_value();
        if (!result.contains(data))
            result.add(data);

        l.next();
    }
    return result;
}

int main()
{
    int size = 2;

    /*IntArray ar1(size);
    IntArray ar2(size);

    cin >> ar1 >> ar2;
    cout << ar1 << ar2;
    cout << ar1 * ar2;*/


    /*RationalArray ar1(size);
    RationalArray ar2(size);

    cin >> ar1 >> ar2;
    cout << ar1 << ar2;

    RationalNumber scal_product = ar1 * ar2;
    cout << scal_product;*/

    /*Array<int> ar1(size);
    Array<int> ar2(size);

    cin >> ar1 >> ar2;
    cout << ar1 << ar2;
    cout << ar1 * ar2 << endl;
    cout << ar1 + ar2;*/

   /* Array<RationalNumber> ar1(size);
    Array<RationalNumber> ar2(size);
    
    cin >> ar1 >> ar2;
    cout << ar1 << ar2;
    RationalNumber scal_product = ar1 * ar2;
    cout << scal_product << endl;
    cout << ar1 + ar2;*/

    /*RationalMatrix mat1(size);
    RationalMatrix mat2(size);
    cin >> mat1;
    cout << endl;
    cin >> mat2;

    cout << mat1 << mat2;

    cout << mat1 + mat2;
    
    cout << mat1 * mat2;*/

    /*List<int> l1;
    cin >> l1;
    cout << l1;
    
    List<int> l2;
    cin >> l2;
    cout << l2;

    bool are_equal = l1 == l2;
    cout << are_equal << endl;

    l2 = l1;
    cout << l2;*/


    /*l1.delete_current();
    l1.add_after_current(10);
    l1.add_before_current(10);
    cout << l1;*/

    /*List<int> l1 = create_from_file("l1.txt");
    cout << l1;
    List<int> l2 = create_from_file("l2.txt");
    cout << l2;
    List<int> l3 = create_from_file("l3.txt");
    cout << l3;

    List<int> l4 = l1_and_l2_minus_l3(l1, l2, l3);
    cout << l4;

    List<int> l5 = copy_without_doubles(l4);
    cout << l5;*/

    SortedList<int> l1 = creates_from_file("l1.txt");
    cout << l1;
    SortedList<int> l2 = creates_from_file("l2.txt");
    cout << l2;
    SortedList<int> l3 = creates_from_file("l3.txt");
    cout << l3;

    SortedList<int> l4 = l1_and_l2_minus_l3(l1, l2, l3);
    cout << l4;

    SortedList<int> l5 = copy_without_doubles(l4);
    cout << l5;


    List<int> l;
    cin >> l;
    SortedList<int> sl = l;
    cout << sl;

}

