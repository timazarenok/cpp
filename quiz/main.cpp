#include <iostream>
#include <string>
#include <vector>
struct Variant
{
    std::string m_text;
    bool m_is_right = false;
    Variant() = default;
    Variant(std::string text, bool is_right): m_text(text), m_is_right(is_right){}
};

struct Question
{
    std::string m_text;
    std::vector<Variant> m_variants;
    Question() = default;
    Question(std::string text, std::vector<Variant> variants): m_text(text), m_variants(variants){}
    void add_variant(const Variant& a)
    {
        m_variants.push_back(a);
    }
    bool is_right_answer(int i)
    {
        return m_variants[i].m_is_right;
    }
};

struct Quiz
{
    std::vector<Question> m_q;
    std::vector<Question>::iterator m_current = m_q.begin();
    Quiz() = default;
    Quiz(std::vector<Question> q, std::vector<Question>::iterator current): m_q(q), m_current(current){}
    void next()
    {
        ++m_current;
    }
    std::vector<Question>::iterator get_current_question()
    {
        return m_current;
    }
    bool has_next()
    {
        return m_current == m_q.end();
    }
    void add_question(const Question& a)
    {
        m_q.push_back(a);
    }
};


int main()
{
    Question a;
    a.m_text = "Valik loh?";
    a.add_variant(Variant("Yes", true));
    a.add_variant(Variant("Maybe", false));
    Quiz quiz;
    quiz.add_question(a);
    for(;quiz.has_next();)
    {
        auto b = quiz.get_current_question();
        std::cout << b->m_text << " ";
    }
    std::cout << a.is_right_answer(0) << std::endl;
    return 0;
}
