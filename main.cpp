#include "yourString.h"
#include <iostream>
#include <string>
int main()
{
    String thread, twine, rope("Hello");
    thread = "world";
    thread += "\n";
    rope += " ";
    twine = rope + thread;

    if (twine(0,4) == String("Hell"))
        std::cout << "Heaven" << std::endl;

    twine[6] = 'W';
    std::cout << twine << std::endl;
    const String hang ("one two three");
    std::cout << twine << std::endl;
    std::cout << hang[2] << std::endl;
    std::cout << hang(1, 20) << std::endl;

    String s1("foo");
    String s2 = "foo";
    // printf("%s\n", s2.c_str());
    if(s1==s2) printf("true\n");
    else printf("false\n");

    String s3("bar");
    s3[0] = 'h';
    std::cout << s3 << std::endl;
    return 0;

}
