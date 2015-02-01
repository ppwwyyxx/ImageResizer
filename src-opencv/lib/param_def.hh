#include "macro_traits.hh"
#include "typecvt.hh"
#include <type_traits>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

#define DEF_PARAM_3(type, name, default_val) 	protected: 		type m_##name = default_val; 	public: 		inline const type &name() const { 			return m_##name; 		}                 template <typename value_t> 		inline auto name(const value_t &v) -> decltype(*this) {                         m_##name = typecvt<type>(v); 			return *this; 		} 

#define DEF_PARAM_6(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_3(__VA_ARGS__); 
        

#define DEF_PARAM_9(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_6(__VA_ARGS__); 
        

#define DEF_PARAM_12(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_9(__VA_ARGS__); 
        

#define DEF_PARAM_15(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_12(__VA_ARGS__); 
        

#define DEF_PARAM_18(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_15(__VA_ARGS__); 
        

#define DEF_PARAM_21(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_18(__VA_ARGS__); 
        

#define DEF_PARAM_24(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_21(__VA_ARGS__); 
        

#define DEF_PARAM_27(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_24(__VA_ARGS__); 
        

#define DEF_PARAM_30(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_27(__VA_ARGS__); 
        

#define DEF_PARAM_33(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_30(__VA_ARGS__); 
        

#define DEF_PARAM_36(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_33(__VA_ARGS__); 
        

#define DEF_PARAM_39(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_36(__VA_ARGS__); 
        

#define DEF_PARAM_42(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_39(__VA_ARGS__); 
        

#define DEF_PARAM_45(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_42(__VA_ARGS__); 
        

#define DEF_PARAM_48(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_45(__VA_ARGS__); 
        

#define DEF_PARAM_51(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_48(__VA_ARGS__); 
        

#define DEF_PARAM_54(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_51(__VA_ARGS__); 
        

#define DEF_PARAM_57(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_54(__VA_ARGS__); 
        

#define DEF_PARAM_60(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_57(__VA_ARGS__); 
        

#define DEF_PARAM_63(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_60(__VA_ARGS__); 
        

#define DEF_PARAM_66(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_63(__VA_ARGS__); 
        

#define DEF_PARAM_69(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_66(__VA_ARGS__); 
        

#define DEF_PARAM_72(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_69(__VA_ARGS__); 
        

#define DEF_PARAM_75(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_72(__VA_ARGS__); 
        

#define DEF_PARAM_78(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_75(__VA_ARGS__); 
        

#define DEF_PARAM_81(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_78(__VA_ARGS__); 
        

#define DEF_PARAM_84(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_81(__VA_ARGS__); 
        

#define DEF_PARAM_87(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_84(__VA_ARGS__); 
        

#define DEF_PARAM_90(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_87(__VA_ARGS__); 
        

#define DEF_PARAM_93(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_90(__VA_ARGS__); 
        

#define DEF_PARAM_96(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_93(__VA_ARGS__); 
        

#define DEF_PARAM_99(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_96(__VA_ARGS__); 
        

#define DEF_PARAM_102(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_99(__VA_ARGS__); 
        

#define DEF_PARAM_105(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_102(__VA_ARGS__); 
        

#define DEF_PARAM_108(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_105(__VA_ARGS__); 
        

#define DEF_PARAM_111(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_108(__VA_ARGS__); 
        

#define DEF_PARAM_114(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_111(__VA_ARGS__); 
        

#define DEF_PARAM_117(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_114(__VA_ARGS__); 
        

#define DEF_PARAM_120(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_117(__VA_ARGS__); 
        

#define DEF_PARAM_123(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_120(__VA_ARGS__); 
        

#define DEF_PARAM_126(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_123(__VA_ARGS__); 
        

#define DEF_PARAM_129(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_126(__VA_ARGS__); 
        

#define DEF_PARAM_132(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_129(__VA_ARGS__); 
        

#define DEF_PARAM_135(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_132(__VA_ARGS__); 
        

#define DEF_PARAM_138(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_135(__VA_ARGS__); 
        

#define DEF_PARAM_141(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_138(__VA_ARGS__); 
        

#define DEF_PARAM_144(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_141(__VA_ARGS__); 
        

#define DEF_PARAM_147(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_144(__VA_ARGS__); 
        

#define DEF_PARAM_150(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_147(__VA_ARGS__); 
        

#define DEF_PARAM_153(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_150(__VA_ARGS__); 
        

#define DEF_PARAM_156(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_153(__VA_ARGS__); 
        

#define DEF_PARAM_159(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_156(__VA_ARGS__); 
        

#define DEF_PARAM_162(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_159(__VA_ARGS__); 
        

#define DEF_PARAM_165(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_162(__VA_ARGS__); 
        

#define DEF_PARAM_168(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_165(__VA_ARGS__); 
        

#define DEF_PARAM_171(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_168(__VA_ARGS__); 
        

#define DEF_PARAM_174(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_171(__VA_ARGS__); 
        

#define DEF_PARAM_177(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_174(__VA_ARGS__); 
        

#define DEF_PARAM_180(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_177(__VA_ARGS__); 
        

#define DEF_PARAM_183(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_180(__VA_ARGS__); 
        

#define DEF_PARAM_186(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_183(__VA_ARGS__); 
        

#define DEF_PARAM_189(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_186(__VA_ARGS__); 
        

#define DEF_PARAM_192(type, name, default_val, ...)         DEF_PARAM_3(type, name, default_val);         DEF_PARAM_189(__VA_ARGS__); 
        

#define DEF_PARAM(...) FORWARD_SUFFIX_BY_NUM_ARGS(DEF_PARAM_, __VA_ARGS__)
    

#define DEF_PARAM_CLASS_STRING_SETTER(...)         public:             template<class val_t>             auto set(const std::string &key, const val_t &val)                 -> decltype(*this) {                 FORWARD_SUFFIX_BY_NUM_ARGS(                     DEF_PARAM_CLASS_STRING_SETTER_, __VA_ARGS__);                 return *this;             }
#define DEF_PARAM_CLASS_PARAM_DUMP(...)         public:             auto dump(std::ostream &os) const -> decltype(*this) {                 FORWARD_SUFFIX_BY_NUM_ARGS(                     DEF_PARAM_CLASS_PARAM_DUMP_, __VA_ARGS__);                 return *this;             }

#define DEF_PARAM_CLASS_PARAM_LOAD(Name, ...)         public:             static Name load(std::string const &path) {                 return load(std::ifstream(path));             }             static Name load(std::istream &is) {                 return load(std::move(is));             }             static Name load(std::istream &&is) {                 auto ret = new_instance();                 std::string line;                 while (std::getline(is, line)) {                     std::stringstream ss(line);                     std::string name, equal, val;                     ss >> name >> equal >> val;                     ret.set(name, val);                 }                 return ret;             }

#define DEF_PARAM_CLASS_PARAM_NAMES(...)         static const std::vector<std::string> &param_names() {             static std::vector<std::string> names = {                 FORWARD_SUFFIX_BY_NUM_ARGS(                     DEF_PARAM_CLASS_PARAM_NAMES_, __VA_ARGS__)             };             return names;         }

    

#define DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val)         if (key == #name)             m_##name = typecvt<type>(val)

#define DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val)         os << #name << " = " << name() << std::endl; 
#define DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)             #name,
    

#define DEF_PARAM_CLASS_STRING_SETTER_6(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_3(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_6(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_3(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_6(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_3(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_9(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_6(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_9(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_6(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_9(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_6(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_12(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_9(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_12(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_9(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_12(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_9(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_15(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_12(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_15(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_12(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_15(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_12(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_18(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_15(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_18(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_15(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_18(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_15(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_21(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_18(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_21(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_18(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_21(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_18(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_24(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_21(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_24(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_21(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_24(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_21(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_27(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_24(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_27(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_24(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_27(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_24(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_30(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_27(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_30(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_27(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_30(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_27(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_33(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_30(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_33(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_30(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_33(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_30(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_36(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_33(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_36(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_33(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_36(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_33(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_39(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_36(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_39(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_36(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_39(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_36(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_42(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_39(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_42(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_39(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_42(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_39(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_45(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_42(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_45(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_42(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_45(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_42(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_48(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_45(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_48(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_45(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_48(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_45(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_51(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_48(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_51(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_48(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_51(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_48(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_54(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_51(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_54(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_51(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_54(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_51(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_57(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_54(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_57(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_54(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_57(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_54(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_60(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_57(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_60(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_57(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_60(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_57(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_63(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_60(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_63(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_60(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_63(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_60(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_66(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_63(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_66(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_63(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_66(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_63(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_69(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_66(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_69(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_66(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_69(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_66(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_72(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_69(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_72(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_69(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_72(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_69(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_75(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_72(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_75(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_72(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_75(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_72(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_78(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_75(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_78(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_75(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_78(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_75(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_81(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_78(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_81(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_78(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_81(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_78(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_84(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_81(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_84(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_81(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_84(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_81(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_87(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_84(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_87(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_84(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_87(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_84(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_90(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_87(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_90(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_87(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_90(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_87(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_93(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_90(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_93(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_90(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_93(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_90(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_96(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_93(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_96(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_93(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_96(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_93(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_99(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_96(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_99(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_96(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_99(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_96(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_102(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_99(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_102(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_99(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_102(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_99(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_105(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_102(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_105(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_102(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_105(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_102(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_108(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_105(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_108(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_105(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_108(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_105(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_111(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_108(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_111(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_108(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_111(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_108(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_114(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_111(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_114(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_111(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_114(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_111(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_117(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_114(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_117(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_114(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_117(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_114(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_120(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_117(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_120(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_117(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_120(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_117(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_123(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_120(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_123(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_120(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_123(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_120(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_126(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_123(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_126(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_123(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_126(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_123(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_129(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_126(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_129(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_126(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_129(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_126(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_132(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_129(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_132(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_129(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_132(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_129(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_135(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_132(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_135(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_132(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_135(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_132(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_138(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_135(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_138(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_135(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_138(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_135(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_141(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_138(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_141(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_138(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_141(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_138(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_144(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_141(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_144(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_141(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_144(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_141(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_147(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_144(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_147(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_144(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_147(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_144(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_150(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_147(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_150(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_147(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_150(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_147(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_153(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_150(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_153(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_150(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_153(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_150(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_156(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_153(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_156(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_153(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_156(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_153(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_159(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_156(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_159(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_156(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_159(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_156(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_162(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_159(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_162(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_159(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_162(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_159(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_165(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_162(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_165(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_162(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_165(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_162(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_168(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_165(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_168(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_165(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_168(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_165(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_171(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_168(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_171(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_168(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_171(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_168(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_174(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_171(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_174(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_171(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_174(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_171(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_177(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_174(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_177(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_174(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_177(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_174(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_180(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_177(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_180(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_177(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_180(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_177(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_183(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_180(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_183(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_180(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_183(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_180(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_186(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_183(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_186(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_183(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_186(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_183(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_189(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_186(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_189(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_186(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_189(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_186(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS_STRING_SETTER_192(type, name, default_val, ...)         DEF_PARAM_CLASS_STRING_SETTER_3(type, name, default_val);         DEF_PARAM_CLASS_STRING_SETTER_189(__VA_ARGS__);

#define DEF_PARAM_CLASS_PARAM_DUMP_192(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_DUMP_3(type, name, default_val);         DEF_PARAM_CLASS_PARAM_DUMP_189(__VA_ARGS__); 
#define DEF_PARAM_CLASS_PARAM_NAMES_192(type, name, default_val, ...)         DEF_PARAM_CLASS_PARAM_NAMES_3(type, name, default_val)         DEF_PARAM_CLASS_PARAM_NAMES_189(__VA_ARGS__) 
        

#define DEF_PARAM_CLASS(Name, ...)         class Name {             Name clone() {                 return *this;             }             static Name new_instance() {                 return Name();             }             DEF_PARAM(__VA_ARGS__);             DEF_PARAM_CLASS_STRING_SETTER(__VA_ARGS__);             DEF_PARAM_CLASS_PARAM_LOAD(Name, __VA_ARGS__);             DEF_PARAM_CLASS_PARAM_DUMP(__VA_ARGS__);             DEF_PARAM_CLASS_PARAM_NAMES(__VA_ARGS__);         };

