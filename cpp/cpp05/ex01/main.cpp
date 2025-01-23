#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        {
            Bureaucrat b("hoseoson", 4);
            // Form form("form1", 0, 151, 3); // grade 오류
        }
        std::cout << "---------------" << std::endl;
        {
            Bureaucrat b("hoseoson", 4);
            Form form("form1", 0, 5, 3);
            std::cout << form << std::endl;

            form.beSigned(b);
            std::cout << form << std::endl;
            // form.beSigned(b); // 중복 사인 애러
            // std::cout << form << std::endl;
        }
        std::cout << "---------------" << std::endl;
        {
            Bureaucrat b("hoseoson", 6);
            Form form("form2", 0, 5, 3);
            std::cout << form << std::endl;

            // form.beSigned(b); // grade 낮아서 애러.
            // std::cout << form << std::endl;
        }
        std::cout << "---------------" << std::endl;
        {
            Bureaucrat b("hoseoson", 4);
            Form form("form3", 0, 5, 3);
            std::cout << form << std::endl;

            b.signForm(form);
            std::cout << form << std::endl;
            b.signForm(form);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
