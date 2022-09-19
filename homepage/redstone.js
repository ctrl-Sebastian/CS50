function toggleMenu(){
    let navigation = document.querySelector('.navigation');
    let toggle = document.querySelector('.toggle');
    navigation.classList.toggle('activate');
    toggle.classList.toggle('activate');
}

const starsEl = document.querySelectorAll(".fa-star");

const emojisEl = document.querySelectorAll(".fa-regular");

const colorsArray = ["red", "orange", "lightblue", "lightgreen", "green"];

updateRating(0);

console.log(starsEl);

starsEl.forEach((starEl, index) =>{
    starEl.addEventListener("click", ()=> {
        updateRating(index)
    });
});

function updateRating(index){
    starsEl.forEach((starsEl, idx)=>{
        if(idx < index + 1){
            starsEl.classList.add("active");
        }else{
            starsEl.classList.remove("active");
        }
    });

    emojisEl.forEach((emojiEl) => {
        emojiEl.style.transform =
        `translateX(-${index * 50}px)`;
        emojiEl.style.color = colorsArray[index]
    });
}

Swal.fire({
    title: 'KLK',
    text: 'follow for more advises',
    icon: 'error',
    confirmButtonText: 'Cool'
  })