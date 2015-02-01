
    #pragma once
    #include "typecvt.hh"
    #include "macro_traits.hh"

    #include <map>
    #include <cctype>
    #include <vector>
    #include <string>
    #include <cassert>
    #include <fstream>
    #include <sstream>
    #include <iostream>
    #include <algorithm>
    #include <stdexcept>
    #include <type_traits>

    
#define DEF_POSITIONAL_ARGS \
                public: \
                    std::vector<std::string> positional_args; \
        
#define POSITIONAL_ARGS positional_args

            #define DEF_ARGUMENT_55(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_50(__VA_ARGS__);
        
            #define DEF_ARGUMENT_50(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_45(__VA_ARGS__);
        
            #define DEF_ARGUMENT_45(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_40(__VA_ARGS__);
        
            #define DEF_ARGUMENT_40(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_35(__VA_ARGS__);
        
            #define DEF_ARGUMENT_35(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_30(__VA_ARGS__);
        
            #define DEF_ARGUMENT_30(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_25(__VA_ARGS__);
        
            #define DEF_ARGUMENT_25(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_20(__VA_ARGS__);
        
            #define DEF_ARGUMENT_20(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_15(__VA_ARGS__);
        
            #define DEF_ARGUMENT_15(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_10(__VA_ARGS__);
        
            #define DEF_ARGUMENT_10(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_5(__VA_ARGS__);
        
            #define DEF_ARGUMENT_5(type, name, default_val, presence, opt_parse_code, ...) \
                \
                public: \
                    type name = typecvt<type>(default_val); \
        
        
        #define DEF_ARGUMENT(...) FORWARD_SUFFIX_BY_NUM_ARGS(DEF_ARGUMENT_, __VA_ARGS__)
    

            #define DEF_ARGUMENT_PARSER_55(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_PARSER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_PARSER_50(__VA_ARGS__);
        
            #define DEF_ARGUMENT_PARSER_50(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_PARSER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_PARSER_45(__VA_ARGS__);
        
            #define DEF_ARGUMENT_PARSER_45(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_PARSER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_PARSER_40(__VA_ARGS__);
        
            #define DEF_ARGUMENT_PARSER_40(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_PARSER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_PARSER_35(__VA_ARGS__);
        
            #define DEF_ARGUMENT_PARSER_35(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_PARSER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_PARSER_30(__VA_ARGS__);
        
            #define DEF_ARGUMENT_PARSER_30(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_PARSER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_PARSER_25(__VA_ARGS__);
        
            #define DEF_ARGUMENT_PARSER_25(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_PARSER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_PARSER_20(__VA_ARGS__);
        
            #define DEF_ARGUMENT_PARSER_20(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_PARSER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_PARSER_15(__VA_ARGS__);
        
            #define DEF_ARGUMENT_PARSER_15(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_PARSER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_PARSER_10(__VA_ARGS__);
        
            #define DEF_ARGUMENT_PARSER_10(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_PARSER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_PARSER_5(__VA_ARGS__);
        
            #define DEF_ARGUMENT_PARSER_5(type, name, default_val, presence, opt_parse_code, ...) \
                \
                { \
                    auto &___var = name; \
                    std::string ___type = #type; \
                    std::string ___name = #name; \
                    std::string ___default_val = #default_val; \
                    int ___presence = presence; \
                    opt_parse_code; \
                }
        
        
        #define DEF_ARGUMENT_PARSER(...) FORWARD_SUFFIX_BY_NUM_ARGS(DEF_ARGUMENT_PARSER_, __VA_ARGS__)
    

            #define DEF_ARGUMENT_CHECK_55(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_CHECK_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_CHECK_50(__VA_ARGS__);
        
            #define DEF_ARGUMENT_CHECK_50(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_CHECK_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_CHECK_45(__VA_ARGS__);
        
            #define DEF_ARGUMENT_CHECK_45(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_CHECK_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_CHECK_40(__VA_ARGS__);
        
            #define DEF_ARGUMENT_CHECK_40(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_CHECK_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_CHECK_35(__VA_ARGS__);
        
            #define DEF_ARGUMENT_CHECK_35(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_CHECK_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_CHECK_30(__VA_ARGS__);
        
            #define DEF_ARGUMENT_CHECK_30(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_CHECK_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_CHECK_25(__VA_ARGS__);
        
            #define DEF_ARGUMENT_CHECK_25(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_CHECK_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_CHECK_20(__VA_ARGS__);
        
            #define DEF_ARGUMENT_CHECK_20(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_CHECK_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_CHECK_15(__VA_ARGS__);
        
            #define DEF_ARGUMENT_CHECK_15(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_CHECK_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_CHECK_10(__VA_ARGS__);
        
            #define DEF_ARGUMENT_CHECK_10(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_CHECK_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_CHECK_5(__VA_ARGS__);
        
            #define DEF_ARGUMENT_CHECK_5(type, name, default_val, presence, opt_parse_code, ...) \
                \
            switch (presence) { \
                case OPTIONAL: \
                    break; \
                case REQUIRED: \
                    if (arg_status[#name] != OptionInfo::OPT_PRESENT) { \
                        auto options = ___m_opt_info[#name].get_options(); \
                        throw std::runtime_error( \
                            "`" + options.back() + \
                            "' required but not specified."); \
                    } \
                    break; \
                default: \
                    throw std::runtime_error( \
                        ("unrecognized presence value for argument `" \
                        #name \
                        "': ") + \
                        std::to_string(presence)); \
            }
        
        
        #define DEF_ARGUMENT_CHECK(...) FORWARD_SUFFIX_BY_NUM_ARGS(DEF_ARGUMENT_CHECK_, __VA_ARGS__)
    

            #define DEF_ARGUMENT_DUMP_55(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_DUMP_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_DUMP_50(__VA_ARGS__);
        
            #define DEF_ARGUMENT_DUMP_50(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_DUMP_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_DUMP_45(__VA_ARGS__);
        
            #define DEF_ARGUMENT_DUMP_45(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_DUMP_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_DUMP_40(__VA_ARGS__);
        
            #define DEF_ARGUMENT_DUMP_40(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_DUMP_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_DUMP_35(__VA_ARGS__);
        
            #define DEF_ARGUMENT_DUMP_35(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_DUMP_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_DUMP_30(__VA_ARGS__);
        
            #define DEF_ARGUMENT_DUMP_30(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_DUMP_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_DUMP_25(__VA_ARGS__);
        
            #define DEF_ARGUMENT_DUMP_25(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_DUMP_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_DUMP_20(__VA_ARGS__);
        
            #define DEF_ARGUMENT_DUMP_20(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_DUMP_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_DUMP_15(__VA_ARGS__);
        
            #define DEF_ARGUMENT_DUMP_15(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_DUMP_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_DUMP_10(__VA_ARGS__);
        
            #define DEF_ARGUMENT_DUMP_10(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_DUMP_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_DUMP_5(__VA_ARGS__);
        
            #define DEF_ARGUMENT_DUMP_5(type, name, default_val, presence, opt_parse_code, ...) \
                \
            os << #name << " = " << name << std::endl; \
        
        
        #define DEF_ARGUMENT_DUMP(...) FORWARD_SUFFIX_BY_NUM_ARGS(DEF_ARGUMENT_DUMP_, __VA_ARGS__)
    

            #define DEF_ARGUMENT_SETTER_55(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_SETTER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_SETTER_50(__VA_ARGS__);
        
            #define DEF_ARGUMENT_SETTER_50(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_SETTER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_SETTER_45(__VA_ARGS__);
        
            #define DEF_ARGUMENT_SETTER_45(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_SETTER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_SETTER_40(__VA_ARGS__);
        
            #define DEF_ARGUMENT_SETTER_40(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_SETTER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_SETTER_35(__VA_ARGS__);
        
            #define DEF_ARGUMENT_SETTER_35(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_SETTER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_SETTER_30(__VA_ARGS__);
        
            #define DEF_ARGUMENT_SETTER_30(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_SETTER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_SETTER_25(__VA_ARGS__);
        
            #define DEF_ARGUMENT_SETTER_25(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_SETTER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_SETTER_20(__VA_ARGS__);
        
            #define DEF_ARGUMENT_SETTER_20(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_SETTER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_SETTER_15(__VA_ARGS__);
        
            #define DEF_ARGUMENT_SETTER_15(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_SETTER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_SETTER_10(__VA_ARGS__);
        
            #define DEF_ARGUMENT_SETTER_10(type, name, default_val, presence, opt_parse_code, ...) \
                DEF_ARGUMENT_SETTER_5(type, name, default_val, presence, opt_parse_code); \
                DEF_ARGUMENT_SETTER_5(__VA_ARGS__);
        
            #define DEF_ARGUMENT_SETTER_5(type, name, default_val, presence, opt_parse_code, ...) \
                \
            if (key == #name) \
                name = typecvt<type>(val); \
        
        
        #define DEF_ARGUMENT_SETTER(...) FORWARD_SUFFIX_BY_NUM_ARGS(DEF_ARGUMENT_SETTER_, __VA_ARGS__)
    

        #define OPTIONAL 0
        #define REQUIRED 1
    

                #define OPT_S(SHORT) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT, ___presence, ___default_val, "S"); \
            if (!hit && (argv[cur] == std::string(#SHORT))) { \
                \
            std::string ___opt_str = #SHORT; \
        ; \
                \
                if (cur + 1 < argc) { \
                    ___var = typecvt<std::remove_reference<decltype(___var)>::type>(argv[cur + 1]); \
                    cur += 2; \
                    arg_status[___name] = OptionInfo::OPT_PRESENT; \
                } else { \
                    throw std::runtime_error( \
                        "additional argument needed for option `" + \
                        ___opt_str + "'"); \
                }\
            ; \
                hit = true; \
            } \
        
            
                #define OPT_L(LONG) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #LONG, ___presence, ___default_val, "L"); \
            if (!hit && (argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #LONG; \
        ; \
                \
                if (cur + 1 < argc) { \
                    ___var = typecvt<std::remove_reference<decltype(___var)>::type>(argv[cur + 1]); \
                    cur += 2; \
                    arg_status[___name] = OptionInfo::OPT_PRESENT; \
                } else { \
                    throw std::runtime_error( \
                        "additional argument needed for option `" + \
                        ___opt_str + "'"); \
                }\
            ; \
                hit = true; \
            } \
        
            
                #define OPT_SL(SHORT, LONG) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "SL"); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                if (cur + 1 < argc) { \
                    ___var = typecvt<std::remove_reference<decltype(___var)>::type>(argv[cur + 1]); \
                    cur += 2; \
                    arg_status[___name] = OptionInfo::OPT_PRESENT; \
                } else { \
                    throw std::runtime_error( \
                        "additional argument needed for option `" + \
                        ___opt_str + "'"); \
                }\
            ; \
                hit = true; \
            } \
        
            
                #define OPT_LS(LONG, SHORT) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "LS"); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                if (cur + 1 < argc) { \
                    ___var = typecvt<std::remove_reference<decltype(___var)>::type>(argv[cur + 1]); \
                    cur += 2; \
                    arg_status[___name] = OptionInfo::OPT_PRESENT; \
                } else { \
                    throw std::runtime_error( \
                        "additional argument needed for option `" + \
                        ___opt_str + "'"); \
                }\
            ; \
                hit = true; \
            } \
        
            
                #define OPT_SW(SHORT, SWITCH_TO_VAL) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT, ___presence, ___default_val, "SW"); \
            if (!hit && (argv[cur] == std::string(#SHORT))) { \
                \
            std::string ___opt_str = #SHORT; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_WS(SWITCH_TO_VAL, SHORT) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT, ___presence, ___default_val, "WS"); \
            if (!hit && (argv[cur] == std::string(#SHORT))) { \
                \
            std::string ___opt_str = #SHORT; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_LW(LONG, SWITCH_TO_VAL) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #LONG, ___presence, ___default_val, "LW"); \
            if (!hit && (argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_WL(SWITCH_TO_VAL, LONG) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #LONG, ___presence, ___default_val, "WL"); \
            if (!hit && (argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_SLW(SHORT, LONG, SWITCH_TO_VAL) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "SLW"); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_SWL(SHORT, SWITCH_TO_VAL, LONG) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "SWL"); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_LSW(LONG, SHORT, SWITCH_TO_VAL) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "LSW"); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_LWS(LONG, SWITCH_TO_VAL, SHORT) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "LWS"); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_WSL(SWITCH_TO_VAL, SHORT, LONG) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "WSL"); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_WLS(SWITCH_TO_VAL, LONG, SHORT) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "WLS"); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_SH(SHORT, HELP) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT, ___presence, ___default_val, "SH", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT))) { \
                \
            std::string ___opt_str = #SHORT; \
        ; \
                \
                if (cur + 1 < argc) { \
                    ___var = typecvt<std::remove_reference<decltype(___var)>::type>(argv[cur + 1]); \
                    cur += 2; \
                    arg_status[___name] = OptionInfo::OPT_PRESENT; \
                } else { \
                    throw std::runtime_error( \
                        "additional argument needed for option `" + \
                        ___opt_str + "'"); \
                }\
            ; \
                hit = true; \
            } \
        
            
                #define OPT_HS(HELP, SHORT) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT, ___presence, ___default_val, "HS", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT))) { \
                \
            std::string ___opt_str = #SHORT; \
        ; \
                \
                if (cur + 1 < argc) { \
                    ___var = typecvt<std::remove_reference<decltype(___var)>::type>(argv[cur + 1]); \
                    cur += 2; \
                    arg_status[___name] = OptionInfo::OPT_PRESENT; \
                } else { \
                    throw std::runtime_error( \
                        "additional argument needed for option `" + \
                        ___opt_str + "'"); \
                }\
            ; \
                hit = true; \
            } \
        
            
                #define OPT_LH(LONG, HELP) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #LONG, ___presence, ___default_val, "LH", HELP); \
            if (!hit && (argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #LONG; \
        ; \
                \
                if (cur + 1 < argc) { \
                    ___var = typecvt<std::remove_reference<decltype(___var)>::type>(argv[cur + 1]); \
                    cur += 2; \
                    arg_status[___name] = OptionInfo::OPT_PRESENT; \
                } else { \
                    throw std::runtime_error( \
                        "additional argument needed for option `" + \
                        ___opt_str + "'"); \
                }\
            ; \
                hit = true; \
            } \
        
            
                #define OPT_HL(HELP, LONG) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #LONG, ___presence, ___default_val, "HL", HELP); \
            if (!hit && (argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #LONG; \
        ; \
                \
                if (cur + 1 < argc) { \
                    ___var = typecvt<std::remove_reference<decltype(___var)>::type>(argv[cur + 1]); \
                    cur += 2; \
                    arg_status[___name] = OptionInfo::OPT_PRESENT; \
                } else { \
                    throw std::runtime_error( \
                        "additional argument needed for option `" + \
                        ___opt_str + "'"); \
                }\
            ; \
                hit = true; \
            } \
        
            
                #define OPT_SLH(SHORT, LONG, HELP) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "SLH", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                if (cur + 1 < argc) { \
                    ___var = typecvt<std::remove_reference<decltype(___var)>::type>(argv[cur + 1]); \
                    cur += 2; \
                    arg_status[___name] = OptionInfo::OPT_PRESENT; \
                } else { \
                    throw std::runtime_error( \
                        "additional argument needed for option `" + \
                        ___opt_str + "'"); \
                }\
            ; \
                hit = true; \
            } \
        
            
                #define OPT_SHL(SHORT, HELP, LONG) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "SHL", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                if (cur + 1 < argc) { \
                    ___var = typecvt<std::remove_reference<decltype(___var)>::type>(argv[cur + 1]); \
                    cur += 2; \
                    arg_status[___name] = OptionInfo::OPT_PRESENT; \
                } else { \
                    throw std::runtime_error( \
                        "additional argument needed for option `" + \
                        ___opt_str + "'"); \
                }\
            ; \
                hit = true; \
            } \
        
            
                #define OPT_LSH(LONG, SHORT, HELP) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "LSH", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                if (cur + 1 < argc) { \
                    ___var = typecvt<std::remove_reference<decltype(___var)>::type>(argv[cur + 1]); \
                    cur += 2; \
                    arg_status[___name] = OptionInfo::OPT_PRESENT; \
                } else { \
                    throw std::runtime_error( \
                        "additional argument needed for option `" + \
                        ___opt_str + "'"); \
                }\
            ; \
                hit = true; \
            } \
        
            
                #define OPT_LHS(LONG, HELP, SHORT) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "LHS", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                if (cur + 1 < argc) { \
                    ___var = typecvt<std::remove_reference<decltype(___var)>::type>(argv[cur + 1]); \
                    cur += 2; \
                    arg_status[___name] = OptionInfo::OPT_PRESENT; \
                } else { \
                    throw std::runtime_error( \
                        "additional argument needed for option `" + \
                        ___opt_str + "'"); \
                }\
            ; \
                hit = true; \
            } \
        
            
                #define OPT_HSL(HELP, SHORT, LONG) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "HSL", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                if (cur + 1 < argc) { \
                    ___var = typecvt<std::remove_reference<decltype(___var)>::type>(argv[cur + 1]); \
                    cur += 2; \
                    arg_status[___name] = OptionInfo::OPT_PRESENT; \
                } else { \
                    throw std::runtime_error( \
                        "additional argument needed for option `" + \
                        ___opt_str + "'"); \
                }\
            ; \
                hit = true; \
            } \
        
            
                #define OPT_HLS(HELP, LONG, SHORT) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "HLS", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                if (cur + 1 < argc) { \
                    ___var = typecvt<std::remove_reference<decltype(___var)>::type>(argv[cur + 1]); \
                    cur += 2; \
                    arg_status[___name] = OptionInfo::OPT_PRESENT; \
                } else { \
                    throw std::runtime_error( \
                        "additional argument needed for option `" + \
                        ___opt_str + "'"); \
                }\
            ; \
                hit = true; \
            } \
        
            
                #define OPT_SWH(SHORT, SWITCH_TO_VAL, HELP) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT, ___presence, ___default_val, "SWH", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT))) { \
                \
            std::string ___opt_str = #SHORT; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_SHW(SHORT, HELP, SWITCH_TO_VAL) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT, ___presence, ___default_val, "SHW", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT))) { \
                \
            std::string ___opt_str = #SHORT; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_WSH(SWITCH_TO_VAL, SHORT, HELP) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT, ___presence, ___default_val, "WSH", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT))) { \
                \
            std::string ___opt_str = #SHORT; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_WHS(SWITCH_TO_VAL, HELP, SHORT) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT, ___presence, ___default_val, "WHS", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT))) { \
                \
            std::string ___opt_str = #SHORT; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_HSW(HELP, SHORT, SWITCH_TO_VAL) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT, ___presence, ___default_val, "HSW", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT))) { \
                \
            std::string ___opt_str = #SHORT; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_HWS(HELP, SWITCH_TO_VAL, SHORT) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT, ___presence, ___default_val, "HWS", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT))) { \
                \
            std::string ___opt_str = #SHORT; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_LWH(LONG, SWITCH_TO_VAL, HELP) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #LONG, ___presence, ___default_val, "LWH", HELP); \
            if (!hit && (argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_LHW(LONG, HELP, SWITCH_TO_VAL) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #LONG, ___presence, ___default_val, "LHW", HELP); \
            if (!hit && (argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_WLH(SWITCH_TO_VAL, LONG, HELP) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #LONG, ___presence, ___default_val, "WLH", HELP); \
            if (!hit && (argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_WHL(SWITCH_TO_VAL, HELP, LONG) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #LONG, ___presence, ___default_val, "WHL", HELP); \
            if (!hit && (argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_HLW(HELP, LONG, SWITCH_TO_VAL) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #LONG, ___presence, ___default_val, "HLW", HELP); \
            if (!hit && (argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_HWL(HELP, SWITCH_TO_VAL, LONG) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #LONG, ___presence, ___default_val, "HWL", HELP); \
            if (!hit && (argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_SLWH(SHORT, LONG, SWITCH_TO_VAL, HELP) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "SLWH", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_SLHW(SHORT, LONG, HELP, SWITCH_TO_VAL) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "SLHW", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_SWLH(SHORT, SWITCH_TO_VAL, LONG, HELP) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "SWLH", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_SWHL(SHORT, SWITCH_TO_VAL, HELP, LONG) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "SWHL", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_SHLW(SHORT, HELP, LONG, SWITCH_TO_VAL) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "SHLW", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_SHWL(SHORT, HELP, SWITCH_TO_VAL, LONG) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "SHWL", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_LSWH(LONG, SHORT, SWITCH_TO_VAL, HELP) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "LSWH", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_LSHW(LONG, SHORT, HELP, SWITCH_TO_VAL) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "LSHW", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_LWSH(LONG, SWITCH_TO_VAL, SHORT, HELP) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "LWSH", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_LWHS(LONG, SWITCH_TO_VAL, HELP, SHORT) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "LWHS", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_LHSW(LONG, HELP, SHORT, SWITCH_TO_VAL) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "LHSW", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_LHWS(LONG, HELP, SWITCH_TO_VAL, SHORT) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "LHWS", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_WSLH(SWITCH_TO_VAL, SHORT, LONG, HELP) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "WSLH", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_WSHL(SWITCH_TO_VAL, SHORT, HELP, LONG) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "WSHL", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_WLSH(SWITCH_TO_VAL, LONG, SHORT, HELP) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "WLSH", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_WLHS(SWITCH_TO_VAL, LONG, HELP, SHORT) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "WLHS", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_WHSL(SWITCH_TO_VAL, HELP, SHORT, LONG) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "WHSL", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_WHLS(SWITCH_TO_VAL, HELP, LONG, SHORT) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "WHLS", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_HSLW(HELP, SHORT, LONG, SWITCH_TO_VAL) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "HSLW", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_HSWL(HELP, SHORT, SWITCH_TO_VAL, LONG) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "HSWL", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_HLSW(HELP, LONG, SHORT, SWITCH_TO_VAL) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "HLSW", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_HLWS(HELP, LONG, SWITCH_TO_VAL, SHORT) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "HLWS", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_HWSL(HELP, SWITCH_TO_VAL, SHORT, LONG) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "HWSL", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            
                #define OPT_HWLS(HELP, SWITCH_TO_VAL, LONG, SHORT) \
                    \
            ___m_opt_info[___name] = OptionInfo( ___type, ___name, #SHORT", "#LONG, ___presence, ___default_val, "HWLS", HELP); \
            if (!hit && (argv[cur] == std::string(#SHORT) || argv[cur] == std::string(#LONG))) { \
                \
            std::string ___opt_str = #SHORT", " #LONG; \
        ; \
                \
                ___var = typecvt<std::remove_reference<decltype(___var)>::type>(SWITCH_TO_VAL); \
                cur ++; \
                arg_status[___name] = OptionInfo::OPT_PRESENT; \
            ; \
                hit = true; \
            } \
        
            

    class __STRMANIP {
        public:
            inline static std::string trim_right_copy( \
              const std::string& s, \
              const std::string& delimiters = " \f\n\r\t\v" ) \
            { \
                auto pos = s.find_last_not_of( delimiters ); \
                if (pos == std::string::npos) \
                    return s; \
                return s.substr( 0, pos + 1 ); \
            } \
            \
            inline static std::string trim_left_copy( \
              const std::string& s, \
              const std::string& delimiters = " \f\n\r\t\v" ) \
            { \
                auto pos = s.find_first_not_of( delimiters ); \
                if (pos == std::string::npos) \
                    return s;  \
                return s.substr(pos); \
            } \
            \
            inline static std::string trim_copy( \
              const std::string& s, \
              const std::string& delimiters = " \f\n\r\t\v" ) \
            { \
              return trim_left_copy( trim_right_copy( s, delimiters ), delimiters ); \
            } \
    };
    

        struct OptionInfo { \
            enum { \
                OPT_ABSENT = 0, \
                OPT_PRESENT = 1 \
            }; \
            \
            OptionInfo() {} \
            OptionInfo( \
                std::string const &type, \
                std::string const &name, \
                std::string const &opts,  \
                int presence, \
                std::string const &default_val, \
                std::string const &specifier, \
                std::string const &help = "" \
            ): type(type), name(name), opts(opts), \
                presence(presence), \
                default_val(default_val), specifier(specifier), \
                help(help) \
            {} \
            bool is_switch() const { \
                return specifier.find('W') != std::string::npos; \
            }; \
            std::string get_hint() const { \
                if (is_switch()) \
                    return ""; \
                return " " + get_type_hint() + ":" + get_name_hint(); \
            } \
            std::string get_type_hint() const { \
                std::string ret = type; \
                if (type == "std::string") \
                    ret = "string"; \
                return to_upper(ret); \
            } \
            std::string get_name_hint() const { \
                return to_upper(name); \
            } \
            static std::string to_upper(std::string const& s) { \
                std::string ret; \
                for (size_t i = 0; i < s.length(); i ++) \
                    ret += (char)std::toupper(s[i]); \
                return ret; \
            } \
            static std::vector<std::string> split_opt(std::string const &opts) { \
                auto pos = opts.find(','); \
                if (pos == std::string::npos) \
                        return {__STRMANIP::trim_copy(opts)}; \
                return {__STRMANIP::trim_copy(opts.substr(0, pos)),  \
                    __STRMANIP::trim_copy(opts.substr(pos + 1))}; \
            } \
            std::vector<std::string> get_options() const { \
                auto p = split_opt(opts); \
                std::sort(p.begin(), p.end(), \
                    [](const std::string &a, const std::string &b){ \
                        return a.length() < b.length(); \
                    }); \
                return p;
            }; \
            std::string type, name, opts; \
            int presence; \
            std::string default_val, specifier, help; \
        };
    

    class HelpPriner {
	protected:
		size_t const line_width_max = 80;

		std::vector<std::string> split_opt(std::string const &opts) {
			auto pos = opts.find(',');
			if (pos == std::string::npos)
                                return {__STRMANIP::trim_copy(opts)};
                        return {__STRMANIP::trim_copy(opts.substr(0, pos)),
                            __STRMANIP::trim_copy(opts.substr(pos + 1))};
		}

		std::string gen_opt_usage(const OptionInfo &info) {
			std::string ret;

			auto optstrs = split_opt(info.opts);
			std::sort(optstrs.begin(), optstrs.end(), [](std::string const &a, std::string const &b){
					return a.length() < b.length();
					});

			auto optstr = optstrs[0];
			ret = optstr + info.get_hint();

			if (info.presence == OPTIONAL)
				ret = "[" + ret + "]";
			return ret;
		}

		std::string gen_help_opt(const OptionInfo &info) {
			std::string ret;
			auto optstr = info.opts;
			ret = optstr + info.get_hint();
			return ret;
		}

		std::string gen_usage(std::string const &prog_name, const std::vector<OptionInfo> &infos) {
			size_t const usage_content_width_min = 50;

			std::vector<std::string> opt_usage;
			for (auto &info: infos)
				opt_usage.emplace_back(gen_opt_usage(info));


			std::string cur_line = "Usage: " + prog_name+ " ";
			std::string ret;

			size_t indent = cur_line.length();
			if (indent + usage_content_width_min > line_width_max) {
				indent = std::string("Usage: ").length();
				ret = cur_line + "\n";
				cur_line = std::string(indent, ' ');
			}

			for (size_t cur = 0; cur < opt_usage.size(); ) {
				bool has_content = false;
				while (cur < opt_usage.size()) {
					auto &cur_opt = opt_usage[cur];
					size_t margin_left = 1;
					if (!has_content) {
						margin_left = 0;
					}
					if (cur_line.length() + margin_left + cur_opt.length() < line_width_max) {
						cur_line += std::string(margin_left, ' ') + cur_opt;
						has_content = true;
						cur ++;
					} else break;
				}
				if (!has_content)
					cur_line += opt_usage[cur ++];
				ret += cur_line + "\n";
				cur_line = std::string(indent, ' ');
			}
			ret.pop_back();

			return ret;
		}

		static bool char_in_string(int ch, const std::string &str) {
			for (size_t i = 0; i < str.length(); i ++)
				if (ch == str[i])
					return true;
			return false;
		}

		std::vector<std::string> strsplit(const std::string &str, const std::string &sep = "") {

			std::vector<std::string> ret;

			auto is_sep = [&](int c) -> bool {
				if (sep.length())
					return char_in_string(c, sep);
				return isblank(c);
			};

			for (size_t i = 0; i < str.length(); ) {
				size_t j = i + 1;
				while (j < str.length() && !is_sep(str[j]))
					j ++;
				ret.emplace_back(str.substr(i, j - i));
				i = j + 1;
			}

			return ret;
		}

		std::vector<std::string> format_help_message(
				const std::string &help,
				size_t first_line_width,
				size_t line_width_max) {

			auto words = strsplit(help);
			size_t cur_line_width = first_line_width;
			std::string cur_line;
			std::vector<std::string> ret;
			for (auto &w: words) {
				for (; ;) {
					std::string next = (cur_line.length() == 0 ? "" : " ") + w;
					if (cur_line_width > cur_line.size() + next.length()) {
						cur_line += next;
						break;
					} else {
						ret.emplace_back(cur_line);
						cur_line_width = line_width_max;
						cur_line = "";
					}
				}
			}
			if (cur_line.length())
				ret.emplace_back(cur_line);
			if (ret.size() == 0)
				return {""};
			return ret;
		}


		std::string gen_option_help(const std::vector<OptionInfo> &infos) {
			int const help_message_width_max = 60,
				help_message_width_min = 30;
			std::string ret;

			assert(line_width_max > help_message_width_max);
			size_t help_message_indent = line_width_max - help_message_width_max;

			for (auto &info: infos) {
				std::string cur_line = "  " + gen_help_opt(info);
				if (cur_line.length() + 1 < help_message_indent)
					cur_line += std::string(help_message_indent - 1 - cur_line.size(), ' ');
				cur_line += " ";
				int remain = (int)line_width_max - (int)cur_line.length();

				assert(remain <= help_message_width_max);
				std::vector<std::string> help_message;
				if (remain > help_message_width_min)
					help_message = format_help_message(
							info.help,
							remain,
							help_message_width_max);
				else help_message = format_help_message(
						info.help,
						help_message_width_max,
						help_message_width_max);
				ret += cur_line + help_message[0] + "\n";
				for (size_t j = 1; j < help_message.size(); j ++)
					ret += std::string(help_message_indent, ' ') + help_message[j] + "\n";
			}
			return ret;
		}

	public:
		void print_help(std::ostream &&os, std::string const &prog_name, std::vector<OptionInfo> infos) {

			std::sort(infos.begin(), infos.end(),
					[](const OptionInfo &a, const OptionInfo &b){
					return a.presence > b.presence;
					});

			os << gen_usage(prog_name, infos) << std::endl;
			os << "Options: " << std::endl;
			os << gen_option_help(infos) << std::endl;
		}
		void print_help(std::ostream &os, std::string const &prog_name,
				const std::vector<OptionInfo> &infos) {
			print_help(std::move(os), prog_name, infos);
		}
        };
    

        #define DEF_ARGUMENT_CLASS(Name, ...) \
            class Name { \
                public: \
                    Name() { ___populate_option_info(); } \
                    Name(int argc, char *argv[]) { parse_args(argc, argv); } \
                    DEF_ARGUMENT(__VA_ARGS__); \
                public: \
                    template <typename value_type> \
                    auto set(const std::string &key, const value_type &val) \
                        -> decltype(*this) { \
                        DEF_ARGUMENT_SETTER(__VA_ARGS__); \
                        return *this; \
                    } \
                    bool parse_args(int argc, char *argv[]) { \
                        int cur = 1; \
                        std::map<std::string, int> arg_status; \
                        while (cur < argc) { \
                            bool hit = false; \
                            do { \
                                DEF_ARGUMENT_PARSER(__VA_ARGS__); \
                            } while (0); \
                            if (!hit) { \
                                POSITIONAL_ARGS.emplace_back(argv[cur]); \
                                cur ++; \
                            } \
                        } \
                        try { \
                            DEF_ARGUMENT_CHECK(__VA_ARGS__); \
                        } catch (std::runtime_error e) { \
                            std::cerr << "Error: " << e.what() << std::endl; \
                            print_help(std::cout, argv[0]); \
                            return false; \
                        } \
                        return true; \
                    } \
                    \
                    inline auto dump(std::ostream &&os) const -> decltype(*this) { \
                        DEF_ARGUMENT_DUMP(__VA_ARGS__); \
                        for (auto &p: POSITIONAL_ARGS) \
                            os << "positional_args" << " = " << p << std::endl; \
                        return *this; \
                    } \
                    inline auto dump(std::ostream &os) const -> decltype(*this) { \
                        return dump(std::move(os)); \
                    } \
                    inline auto dump(const std::string &path) const -> decltype(*this) { \
                        return dump(std::ofstream(path)); \
                    } \
                    \
                    inline static auto load(std::istream &&is) -> Name { \
                        auto ret = Name(); \
                        std::string line; \
                        int lineno = 0; \
                        while (std::getline(is, line)) { \
                            lineno ++; \
                            auto pos = line.find('='); \
                            if (pos == std::string::npos) { \
                                std::cerr << "Error reading line " << lineno << " while loading " #Name << std::endl; \
                                continue; \
                            } \
                            std::string name, val; \
                            if (pos > 0) \
                                name = line.substr(0, pos); \
                            val = line.substr(pos + 1); \
                            name = __STRMANIP::trim_copy(name); \
                            val = __STRMANIP::trim_copy(val); \
                            if (name == "positional_args") \
                                ret.POSITIONAL_ARGS.emplace_back(val); \
                            else ret.set(name, val); \
                        } \
                        ret.___populate_option_info(); \
                        return ret; \
                    } \
                    inline static auto load(std::istream &is) -> Name { \
                        return load(std::move(is)); \
                    } \
                    inline static auto load(const std::string &path) -> Name { \
                        return load(std::ifstream(path)); \
                    } \
                    \
                    inline auto print_help(std::ostream &&os, std::string const &prog_name) const -> decltype(*this) { \
                        HelpPriner().print_help(os, prog_name, get_option_info()); \
                        return *this; \
                    } \
                    inline auto print_help(std::ostream &os, std::string const &prog_name) const -> decltype(*this) { \
                        return print_help(std::move(os), prog_name); \
                    } \
                    inline std::vector<OptionInfo> get_option_info() const { \
                        std::vector<OptionInfo> ret; \
                        for (auto &p: ___m_opt_info) \
                            ret.emplace_back(p.second); \
                        return ret; \
                    } \
                    DEF_POSITIONAL_ARGS \
                protected: \
                    std::map<std::string, OptionInfo> ___m_opt_info; \
                    void ___populate_option_info() { \
                        int argc = 1; \
                        std::vector<std::string> argv = {"__dummy"}; \
                        int cur = 0; \
                        std::map<std::string, int> arg_status; \
                        bool hit = false; \
                        do { \
                            DEF_ARGUMENT_PARSER(__VA_ARGS__); \
                        } while (0); \
                    } \
            };

    
