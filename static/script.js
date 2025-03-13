
document.getElementById('toggle-btn').addEventListener('click', function() {
    var sideDrawer = document.getElementById('side-drawer');
    var overlay = document.getElementById('overlay');
    
    if (sideDrawer.style.width === '250px') {
        sideDrawer.style.width = '0';
        sideDrawer.style.opacity = '0';
        overlay.style.display = 'none';
    } else {
        sideDrawer.style.width = '250px';
        sideDrawer.style.opacity = '1';
        overlay.style.display = 'block';
    }
});





document.getElementById('overlay').addEventListener('click', function() {
    var sideDrawer = document.getElementById('side-drawer');
    var overlay = document.getElementById('overlay');
    
    sideDrawer.style.width = '0';
    sideDrawer.style.opacity = '0';
    overlay.style.display = 'none';
});





    document.addEventListener('DOMContentLoaded', function() {
        const faqs = document.querySelectorAll('.faq-question');

        faqs.forEach(faq => {
            faq.addEventListener('click', function() {
                this.parentElement.classList.toggle('open');
            });
        });
    });


function changeFontFamily(fontFamily) {
    document.body.style.fontFamily = fontFamily;
}

changeFontFamily("'Montserrat', sans-serif");



function validateForm() {
    var from_stn = document.getElementById("from_stn").value.trim().toUpperCase();
    var to_stn = document.getElementById("to_stn").value.trim().toUpperCase();
    if (from_stn === to_stn) {
        alert("Boarding and Terminating stations can't be Same.");
        return false;
    }
    return true;
}











var modal = document.getElementById("myModal");

    var btn = document.getElementById("openModalBtn");

    var span = document.getElementsByClassName("close")[0];

    btn.onclick = function() {
        modal.style.display = "block";
    }

    span.onclick = function() {
        modal.style.display = "none";
    }

    window.onclick = function(event) {
        if (event.target == modal) {
            modal.style.display = "none";
        }
    }







document.getElementById('openModalBtn').onclick = function() {
    document.getElementById('myModal').style.display = 'block';
}

window.onclick = function(event) {
    if (event.target == document.getElementById('myModal')) {
        document.getElementById('myModal').style.display = 'none';
    }
}

document.getElementById('loginBtn',).onclick = function() {
    document.getElementById('myModal').style.display = 'none';
    document.getElementById('login-message').style.display = 'block';
}




