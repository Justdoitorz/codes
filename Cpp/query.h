#ifndef __QUERY_H__
#define __QUERY_H__


#include <string>
#include <memory>

//class Query;
class QueryResult {};
class TextQuery{};
class Query_base {
    friend class Query;
protected:
    //using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};

class Query {
    friend Query operator~(const Query&);
    friend Query operator&(const Query&, const Query&);
    friend Query operator|(const Query&, const Query&);
public:
    Query(const std::string&);
    QueryResult eval(const TextQuery &t) const
    {
        return q->eval(t);
    }
    std::string rep() const
    {
        return q->rep();
    }
private:
    Query(std::shared_ptr<Query_base> query) : q(query) { }
    std::shared_ptr<Query_base> q;
};

inline std::ostream& operator<<(std::ostream &os, const Query &query)
{
    return os << query.rep();
}


class WordQuery: public Query_base {
    friend class Query;
    WordQuery(const std::string& s) : query_word(s) { }
    QueryResult eval(const TextQuery& t) const
    {
        //return t.query(query_word);
    }
    std::string rep() const
    {
        return query_word;
    }
    std::string query_word;
};

inline Query::Query(const std::string &s): q(new WordQuery(s)) { }

class NotQuery: public Query_base {
    friend Query operator~(const Query&);
    NotQuery(const Query& q) : query(q) { }
    std::string rep() const { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery&) const;
    Query query;
};

inline Query operator~(const Query &operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery: public Query_base {
protected:
    BinaryQuery(const Query& l, const Query& r, std::string s) :
        lhs(l), rhs(r), opSym(s) { }
    std::string rep() const
    {
        return "(" + lhs.rep() + opSym + rhs.rep() + ")";
    }
    //QueryResult eval(const TextQuery&) const;
    Query lhs, rhs;
    std::string opSym;
};

class AndQuery: public BinaryQuery {
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& l, const Query& r) :
        BinaryQuery(l, r, "&") { }
    QueryResult eval(const TextQuery&) const{};
};

inline Query operator&(const Query& l, const Query& r)
{
    return std::shared_ptr<Query_base>(new AndQuery(l, r));
}

class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& l, const Query& r) :
        BinaryQuery(l, r, "|") { }
    QueryResult eval(const TextQuery&) const{};
};

inline Query operator|(const Query& l, const Query& r)
{
    return std::shared_ptr<Query_base>(new OrQuery(l, r));
}

#endif
