//程序库开发人员
class Library{
public:
	//稳定 template method，需要稳定的算法框架，即保持Step1，Step3，Step5稳定
	//稳定中有变化
	//稳定的写成普通函数，不稳定的写成虚函数
    void Run(){
        
        Step1();

        if (Step2()) { //支持变化 ==> 虚函数的多态调用
            Step3(); 
        }

        for (int i = 0; i < 4; i++){
            Step4(); //支持变化 ==> 虚函数的多态调用
        }

        Step5();

    }
	virtual ~Library(){ }

protected:
	
	void Step1() { //稳定
        //.....
    }
	void Step3() {//稳定
        //.....
    }
	void Step5() { //稳定
		//.....
	}

	virtual bool Step2() = 0;//变化
    virtual void Step4() =0; //变化
};