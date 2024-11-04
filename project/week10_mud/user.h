class User {
private:
    int hp; // 체력

public:
    User(); // 생성자
    void DecreaseHP(int dec_hp); // 체력 감소 함수
    void IncreaseHP(int inc_hp); // 체력 증가 함수
    int GetHP() const; // 체력 반환 함수
};

