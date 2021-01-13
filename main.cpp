#include <iostream>
#include <string>
class Caesar {
 public:
  Caesar() : key{3} { setPlainText("CAESAR"); }
  std::string operator()() { return setPlainText("Caesar"); }

  std::string setPlainText(std::string str) {
    plainText = str;
    return updateCipher();
  }
  std::string updateCipher() {
    cipher.clear();
    for (char val : plainText) {
      val = shiftChar(val, key);
      cipher.insert(cipher.begin() + cipher.size(), val);
    }
    return cipher;
  }
  std::string decrypt(int key) {
    key = -key;
    std::string str{" "};
    str.clear();
    for (char val : cipher) {
      val = shiftChar(val, key);
      str.insert(str.begin() + str.size(), val);
    }
    return str;
  }

 private:
  char shiftChar(int ch, int key) {
    ch += key;
    if (key > 0) {
      ch %= first;
      ch += first;
    } else {
      if (ch < first) {
        ch = last - (first - ch) + 1;
      }
    }
    return ch;
  }
  std::string plainText;
  int key;
  std::string cipher;

  const char first{('a' < 'A' ? 'a' : 'A')};
  const char last{('z' < 'Z' ? 'z' : 'Z')};
};

int main() {
  Caesar sezar;
  std::cout << sezar.setPlainText("HelloWorld") << std::endl;
  std::cout << sezar.decrypt(3) << std::endl;
  std::cout << sezar() << std::endl;
  std::cout << sezar.decrypt(3) << std::endl;
  return 0;
}
