#pragma once

#include <string>
#include <memory>

class POSL_Tag
{
    public:
        POSL_Tag(std::string _tag);
        POSL_Tag(std::string _tag, std::shared_ptr<POSL_Tag> _next);

        void addTag(std::shared_ptr<POSL_Tag> _next);
        std::string GetTag();

    private:
        std::string tag;
        std::shared_ptr<POSL_Tag> next;
};
