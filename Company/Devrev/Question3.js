async function getData(){
    let response = await fetch("http://127.0.0.1:8081/products");
    let data=response.json();
    
    data.map((obj)=>{
        if (obj.manufacturer){
        console.log("Product", obj.name, "has price",obj.price,"and manufacturer",obj.manufacturer);
        }
        else{
        console.log("Product", obj.name, "has price",obj.price,"and no manufacturer");
        }
    })
}