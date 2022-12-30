#include <iostream>
#include <string>
#include <tuple>

class Version
{
public:
    // Constructor
    Version(std::uint8_t major, std::uint8_t minor = 0, std::uint8_t patch = 0)
        : m_major(major), m_minor(minor), m_patch(patch) {}

    // Getters for the major, minor, and patch numbers
    std::uint8_t getMajor() const { return m_major; }
    std::uint8_t getMinor() const { return m_minor; }
    std::uint8_t getPatch() const { return m_patch; }

    // Comparison operators
    bool operator==(const Version& other) const
    {
        return std::tie(m_major, m_minor, m_patch) == std::tie(other.m_major, other.m_minor, other.m_patch);
    }
    bool operator!=(const Version& other) const
    {
        return !(*this == other);
    }
    bool operator<(const Version& other) const
    {
        return std::tie(m_major, m_minor, m_patch) < std::tie(other.m_major, other.m_minor, other.m_patch);
    }
    bool operator<=(const Version& other) const
    {
        return (*this < other) || (*this == other);
    }
    bool operator>(const Version& other) const
    {
        return !(*this <= other);
    }
    bool operator>=(const Version& other) const
    {
        return !(*this < other);
    }

private:
    std::uint8_t m_major;
    std::uint8_t m_minor;
    std::uint8_t m_patch;
};

// Stream insertion operator to make it easy to output a Version object
std::ostream& operator<<(std::ostream& out, const Version& v)
{
    out << v.getMajor() << '.' << v.getMinor() << '.' << v.getPatch();
    return out;
}

// A custom literal to make it easy to create Version objects like "1.2.3"_v
Version operator"" _v(const char* str,std::size_t /*len*/)
{
    std::uint8_t major = 0, minor = 0, patch = 0;
    sscanf_s(str, "%hhu.%hhu.%hhu", &major, &minor, &patch);
    return Version(major, minor, patch);
}

// A custom literal to make it easy to create Version objects like 1.2_v
Version operator"" _v(long double f)
{
    auto f_string = std::to_string(f);
    std::uint8_t major = 0, minor = 0;
    sscanf_s(f_string.c_str(), "%hhu.%hhu", &major, &minor);
    return Version(major, minor, 0);
}

// A custom literal to make it easy to create Version objects like 1.2_v
Version operator"" _v(unsigned long long major)
{

    return Version(static_cast<uint8_t>(major), 0, 0);
}