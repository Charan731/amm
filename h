<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Pay ₹1 to See Balance</title>
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;600&display=swap" rel="stylesheet">
    <style>
        body {
            font-family: 'Poppins', sans-serif;
            background-color: #f8c8d6;
            margin: 0;
            padding: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            flex-direction: column;
        }
        .container {
            text-align: center;
            background-color: white;
            border-radius: 15px;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
            padding: 30px;
            width: 80%;
            max-width: 500px;
        }
        h1 {
            color: #d14377;
            font-size: 2rem;
            margin-bottom: 20px;
        }
        .points {
            text-align: left;
            margin-bottom: 30px;
            font-size: 1.2rem;
        }
        .point {
            margin-bottom: 10px;
        }
        .btn {
            background-color: #4CAF50;
            color: white;
            padding: 12px 20px;
            font-size: 1.2rem;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            transition: 0.3s;
        }
        .btn:hover {
            background-color: #45a049;
        }
        .balance-box {
            display: block;
            margin-top: 20px;
            font-size: 1.5rem;
            color: #4CAF50;
            border: 2px solid #4CAF50;
            border-radius: 10px;
            padding: 10px;
            width: fit-content;
            margin-left: auto;
            margin-right: auto;
        }
        .icons {
            display: flex;
            justify-content: space-between;
            margin-top: 30px;
        }
        .icon {
            font-size: 1.5rem;
            cursor: pointer;
            text-decoration: none;
            color: #4CAF50;
        }
        .signature {
            position: fixed;
            bottom: 10px;
            left: 10px;
            font-size: 1rem;
            font-weight: bold;
            color: #4CAF50;
        }
    </style>
</head>
<body>

<div class="container">
    <h1>Pay ₹1 to See How Many Rupees in This Account</h1>

    <div class="points">
        <div class="point">1. Click the green button below</div>
        <div class="point">2. Pay ₹1</div>
        <div class="point">3. See the Count</div>
        <div class="point">4. Share it with Your Friends</div>
    </div>

    <button class="btn" onclick="payRupee()">Pay ₹1</button>

    <div class="balance-box" id="balance">
        Balance: Hidden
    </div>

    <div class="icons">
        <a href="https://wa.me/8790876817" class="icon" target="_blank">WhatsApp</a>
        <a href="https://www.instagram.com" class="icon" target="_blank">Instagram</a>
        <a href="https://www.facebook.com" class="icon" target="_blank">Facebook</a>
    </div>
</div>

<div class="signature">
    CH.CHARAN
</div>

<script src="https://checkout.razorpay.com/v1/checkout.js"></script>
<script>
    // Load balance from local storage or set to 0 if not present
    let balance = parseInt(localStorage.getItem('balance')) || 0;

    // Show Hidden by default
    document.getElementById('balance').innerText = "Balance: Hidden";

    function payRupee() {
        var options = {
            "key": "rzp_test_4XzgmPZdCxTkEX", 
            "amount": "100", 
            "currency": "INR",
            "name": "Charan's Account",
            "description": "Pay ₹1 to see your balance",
            "image": "https://example.com/logo.png",
            "handler": function (response) {
                // Increase balance only after successful payment
                balance += 1;
                localStorage.setItem('balance', balance);
                document.getElementById('balance').innerText = "Balance: ₹" + balance;
                alert("Payment Successful! Balance updated.");
            },
            "prefill": {
                "contact": "8790876817",
                "email": "charan@example.com"
            },
            "theme": {
                "color": "#4CAF50"
            }
        };
        var rzp1 = new Razorpay(options);
        rzp1.open();
    }
</script>

</body>
</html>