let ws = new WebSocket('ws://' + window.location.hostname + ':81/');
ws.onmessage = function(event)
{
  let data = JSON.parse(event.data);
  updateCardPercentage("distance", data.distance, "cm");
  updateCardPercentage("temperature", data.temperature.toFixed(1), "&deg;C");
  updateCardPercentage("potentiometer", data.potentiometer, "%");
}


function updateCardPercentage(cardId, value, unit){
  const card = document.getElementBy(cardId);
  const text = card.querySelector('.number>h2');
  const circle = card.querySelector('svg circle:nth-child(2)');

  text.innerHTML = `${value}<span>${unit}<span>`;

  const radius = circle.r.baseVal.value;
  const circumference = radius * 2 * Math.PI;
  
    if(cardId == "potentiometer"){

      const offset = circumference - (value/100) * circumference;
      circle.style.strokeDashoffset = offset;

      if(value>=80){
        circle.style.stroke = '#00ff43';
      }

      else if(value>=40){
        circle.style.stroke = '#41c2c3';
      }

      else{circle.style.stroke = '#ff04f7';}


    }

    else if(cardId === "temperatura"){

      const offset = circumference - (value/40) * circumference;
      circle.style.strokeDashoffset = offset;
      circle.style.stroke = '#00a1ff';
    }

    else {
      const offset = circumference - (value/300) * circumference;
      circle.style.strokeDashoffset = offset;
      circle.style.stroke = '#ec4e0d';
    }

    card.setAttribute('data-value', value)
}