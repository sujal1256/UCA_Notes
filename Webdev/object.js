// function student(fName,obtMarks) {
//     console.log(this);
//     return {
//         fName,
//         obt:obtMarks,
//         checkResults(){
//             console.log(this);
//             console.log(this.obt/500);
//         }
//     }
// }

// const student1 = student();
// student.checkResults();

// class Student{

//     #fName;
//     constructor(fName,obtMarks){
//         this.#fName = fName;
//         this.obt = obtMarks;
//     }

//     checkResults(name){
//         console.log(this);
//         console.log(this.obt/500);
//     }
// }

// const student1 = new Student("Sujal",300);
// const student2 = new Student("Sujal",300);
// student1.obt = 100;
// console.log(student1.obt);
// console.log(student1);

// let arr = [2,5,2,1,5];
// function callbackFunction(index, value) {
//   console.log(index, " : ", value);
// }
// Array.prototype.mapCustom = function (callbackFunction) {
//   for (let i = 0; i < this.length; i++) {
//     callbackFunction(i, this[i]);
//   }
// };
// arr.map(e=>e*e).mapCustom(callbackFunction);



// Learning Private Property
class Student{
    static staticVariable;
    #fName;
    constructor(fName,obtMarks){
        this.#fName = fName;
        this.obt = obtMarks;
    }

    checkResults(name){
        console.log(this);
        console.log(this.obt/500);
    }
}
const student1 = new Student("Sujal",300);
student1.checkResults();
console.log(student1.#fName);

// static fields can not be accessed from the object, they can only be accessed from Class
// Student.staticVariable