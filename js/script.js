$(document).ready(function(){
  $("a.new_window").attr("target", "_blank");


 });


$(function(){

	// $('.box_display').hide();
	// $('.login_page').hide();	
	$('.home_button').click(function(){
		// alert(1)
		$('.home_button.active').removeClass('active');
		$(this).addClass('active');

		if($(this).hasClass('oone')){
			 $('.box_display').hide();
		}
		else{
			 $('.box_display').show();
		}

	})
	$('#login_ref').click(function(a){
		a.preventDefault();
		// alert(1);
		$('.login_page').slideToggle();

	})

	$("#register_button").click(function(){
		rec=$('#register_form').serialize();
		// console.log(rec)
		$.ajax({
			type:"post",
			data:rec,
			url:"register_action.php",
			success:function(abc){
				// alert(abc);
				if(abc=="ok") window.location.reload();
				else alert(abc);
			},
			error:function(err){
				console.log(err);
			}
		})
	})

	$('.drop_btn').click(function(){
		// alert(1)
		// e.preventDefault();
		$('.dropdown-content').slideToggle();
	})

	$('.drop_btn_name').click(function(){
		// alert(1)
		// e.preventDefault();
		$('.dropdown-content_name').slideToggle();
	})


	$('#change_pass').click(function(a){
		// alert(1)
		a.preventDefault();
		// $('.change_password_page').slideToggle();
	})

	$("#change_password_button").click(function(){
		rec=$('#change_password_form').serialize();
		// console.log(rec)
		$.ajax({
			type:"post",
			data:rec,
			url:"change_password_action.php",
			success:function(abc){
				// alert(abc);
				if(abc=="ok") {
					alert("password changed");
					window.location.href='index.php';
				}
				else alert(abc);
			},
			error:function(err){
				console.log(err);
			}
		})
	})

	$("#area_button").click(function(){
		rec=$('#area_form').serialize();
		// console.log(rec)
		$.ajax({
			type:"post",
			data:rec,
			url:"area_action.php",
			success:function(abc){
				
				$('#area_value').val(abc);
				// alert(abc);
				// if(abc=="ok") {
				// 	alert("password changed");
				// 	window.location.href='index.php';
				// }
				// else alert(abc);
				window.location.reload();
			},
			error:function(err){
				console.log(err);
			}
		})
	})

});
