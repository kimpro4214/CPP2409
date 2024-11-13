#include <iostream>
using namespace std;

class Camera{
    private:
        Camera(){}
        static Camera *instance;
    public:
        int photos = 0;
        static Camera *Getinstace();
        void Capture(){
            cout << "사진 촬영이 수행되었음!" << endl;
            photos += 1;
        }
};
Camera* Camera::instance = nullptr; //0도 가능
Camera* Camera::Getinstace(){
    if(!instance) {
        instance = new Camera();
        cout << "첫번째 객체 생성됨" << endl;
        return instance;
    }
    else{
        cout << "이전 객체를 반환함" << endl;
        return instance;
    }
}
int main(){
    Camera* c1 = Camera::Getinstace();
    Camera* c2 = Camera::Getinstace();
    Camera* c3 = Camera::Getinstace();
    c1 -> Capture();
    c2 -> Capture();
    cout << c1->photos;
    return 0;
}