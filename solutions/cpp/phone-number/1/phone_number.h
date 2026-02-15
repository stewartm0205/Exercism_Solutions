#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H
#include <string>
#include <regex>
#include <stdexcept>
#include <iostream>
using namespace std;
namespace phone_number {
    class phone_number {
        private:
            string pn;
        public:
            phone_number(string phone) {
                cout<<"phone="<<phone<<'\n';
                string tn = regex_replace(phone,regex("[ +.\\(\\)\\-]"),"");
                cout<<"pn="<<tn<<'\n';
                if (regex_match(tn,regex("[a-z@:!]+"))) throw std::domain_error("invalid argument 1");
                if (tn.length()==9) throw std::domain_error("invalid argument 2");
                if (tn.length()==11 && tn.substr(0,1)!="1") throw std::domain_error("invalid argument 3");
                if (tn.length()>11) throw std::domain_error("invalid argument 4");
                if (tn.length()==11) tn=tn.substr(1,10);
                cout<<"pn2="<<tn<<'\n';
                if (tn.substr(0,1)=="0") throw std::domain_error("invalid argument 5");
                if (tn.substr(0,1)=="1") throw std::domain_error("invalid argument 6");
                if (tn.substr(3,1)=="0") throw std::domain_error("invalid argument 7");
                if (tn.substr(3,1)=="1") throw std::domain_error("invalid argument 8");
                pn=tn;
            }
            string number() {
                return (pn);
            }
            string area_code() {
                return (pn.substr(0,3));
            }
            string string(phone_number phone) {
                return "("+phone.area_code()+") "+
                phone.number().substr(0,3)+"-"+
                phone.number().substr(3,4);
            }

    };
}  // namespace phone_number

#endif // PHONE_NUMBER_H